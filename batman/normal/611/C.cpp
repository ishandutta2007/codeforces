#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (505)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m,q,dp[N][N];
string s[N];

int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];  
    for(int i=1;i<n;i++)
        dp[i][0]=dp[i-1][0]+(s[i][0]=='.' && s[i-1][0]=='.');
    for(int j=1;j<m;j++)
        for(int i=0;i<n;i++)
        {
            dp[i][j]=dp[i][j-1];
            for(int k=0;k<=i;k++)
                if(s[k][j]=='.' && s[k][j-1]=='.')
                    dp[i][j]++;
            for(int k=1;k<=i;k++)
                if(s[k][j]=='.' && s[k-1][j]=='.')
                    dp[i][j]++;     
        }
    cin>>q;
    while(q--)
    {
        ll a,b,c,d,ans;
        cin>>a>>b>>c>>d;
        a--,b--,c--,d--;
        ans=dp[c][d];
        if(a)
        {
            ans-=dp[a-1][d];
            for(int i=b;i<=d;i++)
                if(s[a][i]=='.' && s[a-1][i]=='.')
                    ans--;  
        }
        if(b)
        {
            ans-=dp[c][b-1];
            for(int i=a;i<=c;i++)
                if(s[i][b]=='.' && s[i][b-1]=='.')
                    ans--;
        }
        if(a && b)ans+=dp[a-1][b-1];
        cout<<ans<<"\n";
    }   
    return 0;
}