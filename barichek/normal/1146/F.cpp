#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

#define md (ll)(998244353)

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

vi reb[arr];
int dp[arr][4];

int C[arr];

void dfs(int now)
{
    if (len(reb[now])==0){
        dp[now][0]=1;
        dp[now][1]=0;
        dp[now][2]=1;
        dp[now][3]=0;
        C[now]=1;
        return;
    }

    for (auto wh:reb[now]){
        dfs(wh);
    }
    int mult=1;
    for (auto wh:reb[now]){
        mult*=C[wh];
        mult%=md;
    }

    /// dp[now][0]
    dp[now][0]=mult;

    /// dp[now][1]
    int kek1=1;
    for (auto wh:reb[now]){
        kek1*=C[wh]+dp[wh][2]+dp[wh][3];
        kek1%=md;
    }
    for (auto wh:reb[now]){
        int lol=mult*inv(C[wh])%md*(dp[wh][2]+dp[wh][3])%md;
        kek1-=lol;
        if (kek1<0){
            kek1+=md;
        }

        dp[now][3]+=lol;
        dp[now][3]%=md;
    }

    kek1-=mult;
    if (kek1<0){
        kek1+=md;
    }
    dp[now][1]=kek1;

    /// dp[now][2]
    dp[now][2]=dp[now][1];

    /// dp[now][3]
    /// calculated

    /// C[now]
    C[now]=(dp[now][0]+dp[now][1])%md;

//    cout<<"now :: "<<now<<"\n";
//    cout<<dp[now][0]<<"\n";
//    cout<<dp[now][1]<<"\n";
//    cout<<dp[now][2]<<"\n";
//    cout<<dp[now][3]<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=2;i<=n;i++){
        int p;
        cin>>p;
        reb[p].pb(i);
    }
    dfs(1);
//    for (int i=1;i<=n;i++){
//        cout<<i<<" :: "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<"\n";
//    }
    cout<<C[1]<<"\n";
}