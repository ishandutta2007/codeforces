#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (55)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,m,a[N][N],ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
	{
		ll sum1=0,sum2=0;
		for(int k=0;k<n;k++)sum1+=a[i][k],sum2+=a[k][j];
		if(sum2>sum1)ans++;
	}
	cout<<ans;
	
	return 0;
}