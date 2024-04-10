#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,a[N],ans[N],num[N];


int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		ll last=a[i];
		for(int i=0;i<N;i++)num[i]=0;
		//cout<<last<<" ";
		ans[a[i]]++;num[a[i]]++;
		for(int j=i+1;j<=n;j++)
		{
			num[a[j]]++;
			if(num[a[j]]>num[last] || (num[a[j]]==num[last] && a[j]<last))last=a[j];
			ans[last]++;
			//cout<<last<<" ";
		}
		//cout<<"\n";
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}