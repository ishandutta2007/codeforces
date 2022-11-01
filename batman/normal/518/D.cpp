//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (2200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ll n,t;
ld p,dp[N][N];

int Sa1378
{ 
    IB
    cin>>n>>p>>t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=t;j++)
            dp[i][j]=(1+dp[i-1][j-1])*p+dp[i][j-1]*(1-p);
    cout<<ST(6)<<fixed<<dp[n][t];
    return 0;
}