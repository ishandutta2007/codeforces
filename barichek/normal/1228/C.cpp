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

int kek[ar];

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

int solve(int p,int n)
{
    vi cur(0);
    int lol=1;
    while (1){
        cur.pb(lol);
        if ((ld)lol*p>2e18){
            break;
        }
        int to=lol*p;
        if (to/lol==p){
            lol=to;
        }
        else{
            break;
        }
    }
//    cout<<"cur :: ";
//    for (auto i:cur){
//        cout<<i<<"\n";
//    }
    for (int i=len(cur)-1;i>=0;i--){
        kek[i]=n/cur[i];
        for (int j=i+1;j<len(cur);j++){
            kek[i]-=kek[j];
        }
    }
    int res=1;
    for (int i=0;i<len(cur);i++){
        res=res*bpow(cur[i]%md,kek[i])%md;
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int x,n;
    cin>>x>>n;
    vi a(0);
    for (int i=2;i*i<=x;i++){
        if (x%i==0){
            a.pb(i);
            while (x%i==0){
                x/=i;
            }
        }
    }
    if (x!=1){
        a.pb(x);
    }
    int res=1;
    for (auto i:a){
        res=res*solve(i,n)%md;
    }
    cout<<res<<"\n";
}