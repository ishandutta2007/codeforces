#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (20)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll r,c,n,m,a[N][N],ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>r>>c>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[x][y]++;
	}
	for(int i=1;i<=r;i++)
		for(int i2=i;i2<=r;i2++)
			for(int j=1;j<=c;j++)
				for(int j2=j;j2<=c;j2++)
				{
					ll cnt=0;
					for(int k=i;k<=i2;k++)
						for(int q=j;q<=j2;q++)
							cnt+=a[k][q];
					if(cnt>=m)ans++;
				}
	cout<<ans;
	return 0;
}