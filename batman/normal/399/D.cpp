#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)2020)
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,m;
ld dp[N][N];
bool mark[2][N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;x--;y--;
        mark[0][x]=1;mark[1][y]=1;
    }
    for(int p=0;p<=n;p++)
        for(int q=0;q<=n;q++)
            if(p || q)
            {
                ll num=p*n+q*n-p*q;
                dp[p][q]=(ld)n*n/num;
                if(p && q)dp[p][q]+=(ld)p*q/num*dp[p-1][q-1];
                if(p)dp[p][q]+=(ld)(p*n-p*q)/num*dp[p-1][q];
                if(q)dp[p][q]+=(ld)(q*n-p*q)/num*dp[p][q-1];
            }
    ll p=0,q=0;
    for(int i=0;i<n;i++)p+=(!mark[0][i]),q+=(!mark[1][i]);
    cout<<fixed<<setprecision(15)<<dp[p][q];
    return 0;
}