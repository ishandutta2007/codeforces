#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (55)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll n,a[N][N],p[N];
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bool is=1;
			for(int k=1;k<=n;k++)
				if(a[j][k]!=i && !mark[k] && j!=k)
					is=0;
			if(is)
			{
				p[j]=i;
				mark[j]=1;
				break;
			}	
		}
	}
	for(int i=1;i<=n;i++)cout<<p[i]<<" ";
    return 0;
}