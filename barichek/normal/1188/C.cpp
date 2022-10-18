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
///#define int long long

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

int rem[arr];

int n,k;
int a[arr];

int dp[ar][ar];
//int pref_dp[ar][ar];

int p[arr];

int get(int L) /// beaut >= L
{
//    cout<<"L :: "<<L<<"\n";
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }
    for (int i=0;i<=n;i++){
        p[i]=0;
    }
    for (int i=1;i<=n;i++){
        p[i]=p[i-1];
        while (p[i]!=i-1&&a[i]-a[p[i]+1]>=L){
            p[i]++;
        }
//        cout<<i<<" :: "<<p[i]<<"\n";
    }
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        dp[i][0]=1;
    }
//    for (int i=0;i<=n;i++){
//        pref_dp[i][0]=1;
//    }
    for (int j=1;j<=k;j++){
        for (int i=1;i<=n;i++){
            dp[i][j]=dp[i-1][j]+dp[p[i]][j-1];
            if (dp[i][j]>=md){
                dp[i][j]-=md;
            }
//            cout<<"dp["<<i<<"]["<<j<<"] :: "<<dp[i][j]<<"\n";
        }
//        for (int i=0;i<=n;i++){
//            pref_dp[i][j]=(i==0?0:pref_dp[i-1][j])+dp[i][j];
//            if (pref_dp[i][j]>=md){
//                pref_dp[i][j]-=md;
//            }
//        }
    }
    return dp[n][k];
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=-1e9;
    sort(a+1,a+n+1);
    int pp=0;
    while (rem[pp]=get(pp)){
        pp++;
    }
    ll ans=0;
    for (int i=0;i<=pp;i++){
//        cout<<i<<" :: "<<rem[i]<<"\n";
        ans+=1ll*i*(rem[i]-rem[i+1])%md;
        ans+=md;
        ans%=md;
    }
    cout<<ans<<"\n";
}