// Zzz
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)55)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=(b%2)?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,m,a,b,ans=INF;
bool x[N][N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>x[i][j];
	cin>>a>>b;
	for(int i=0;i<n-a+1;i++)
		for(int j=0;j<m-b+1;j++)
		{
			ll num=0;
			for(int p=i;p<i+a;p++)
				for(int q=j;q<j+b;q++)
					num+=x[p][q];
			ans=min(ans,num);
		}
	swap(a,b);
	for(int i=0;i<n-a+1;i++)
		for(int j=0;j<m-b+1;j++)
		{
			ll num=0;
			for(int p=i;p<i+a;p++)
				for(int q=j;q<j+b;q++)
					num+=x[p][q];
			ans=min(ans,num);
		}
	cout<<ans;
	return 0;
}