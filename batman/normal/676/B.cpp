#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =20;

ll n,t,ans=1;
ld f[N][N];

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	if(t==0)return cout<<0,0;
	f[1][1]=t-1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=(f[i-1][j-1]+f[i-1][j])/2-1;
			
			if(f[i][j]>=0)ans++;
			f[i][j]=max(f[i][j],(ld)0);
			//cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
		}
	}
	cout<<ans;
	return 0;
}