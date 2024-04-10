//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

#define ar (int)(3000+10)

vi reb[arr];
int dp[ar][ar];
int pref[ar][ar];

int inverse[arr];

int get_inverse(int diff)
{
    if (diff>0){
        return inverse[diff];
    }
    else{
        return -inverse[-diff];
    }
}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        n/=2;
        a=a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

void dfs(int now)
{
    for (int i=1;i<ar;i++){
        dp[now][i]=1;
    }
    for (auto wh:reb[now]){
        dfs(wh);
    }
    for (int i=1;i<ar;i++){
        for (auto wh:reb[now]){
            dp[now][i]=dp[now][i]*pref[wh][i]%md;
        }
    }
    for (int i=1;i<ar;i++){
        pref[now][i]=(pref[now][i-1]+dp[now][i])%md;
    }
}

int get(vector<pii> poly,int D)
{
    int res=0;
    for (int i=0;i<poly.size();i++){
        int cur=poly[i].sec;
        for (int j=0;j<poly.size();j++){
            if (i!=j){
                cur=cur*(D-poly[j].fir)%md;
                if (cur<0){
                    cur+=md;
                }
                cur=cur*get_inverse(poly[i].fir-poly[j].fir)%md;
                if (cur<0){
                    cur+=md;
                }
            }
        }
        res=(res+cur)%md;
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<arr;i++){
        inverse[i]=bpow(i,md-2);
    }

    int n,D;
    cin>>n>>D;
    for (int i=2;i<=n;i++){
        int p;
        cin>>p;
        reb[p].pb(i);
    }
    dfs(1);
    vector<pii> poly(0);
    for (int i=1;i<ar;i++){
        poly.pb(mp(i,pref[1][i]));
    }
//    for (auto i:poly){
//        cout<<i.fir<<" "<<i.sec<<"\n";
//    }
    cout<<get(poly,D)<<"\n";
}