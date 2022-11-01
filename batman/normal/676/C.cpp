#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,k,sum[2][N],ans;
string s;

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++)
		sum[0][i]=sum[0][i-1]+(s[i-1]=='a'),sum[1][i]=sum[1][i-1]+(s[i-1]=='b');
	for(ll i=0,j=0;i<n;i++)
	{
		while(j<n)
		{
			if(s[j]=='a' && sum[0][j+1]-sum[0][i]>k)
				break;
			j++;
		}
		ans=max(ans,j-i);
		if(j==n)break;
	}
	for(ll i=0,j=0;i<n;i++)
	{
		while(j<n)
		{
			if(s[j]=='b' && sum[1][j+1]-sum[1][i]>k)
				break;
			j++;
		}
		ans=max(ans,j-i);
		if(j==n)break;
	}
	cout<<ans;
	return 0;
}