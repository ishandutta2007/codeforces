#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,a[N],dp[2][N];
string s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>s;
    dp[0][0]=(s[0]-'0')*a[0];
    dp[1][0]=a[0];
    for(int i=1;i<n;i++)
    	dp[1][i]=dp[1][i-1]+a[i],dp[0][i]=((s[i]-'0')?max(dp[1][i-1],dp[0][i-1]+a[i]):dp[0][i-1]);
    cout<<dp[0][n-1];	
    return 0;
}