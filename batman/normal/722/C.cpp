#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,a[N],b[N],par[N],sum[N];
bool mark[N];
multiset <ll> s;

ll root(ll x){if(par[x]==-1)return x;return par[x]=root(par[x]);}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],par[i]=-1;
	for(int i=1;i<=n;i++)cin>>b[i];
	stack <ll> ans;
	ans.push(0);
	for(int j=n;j>1;j--)
	{
		ll i=b[j];
		mark[i]=1;
		sum[i]=a[i];
		if(mark[i-1])
		{
			sum[root(i-1)]+=sum[i];
			par[i]=root(i-1);
			s.erase(sum[root(i-1)]);
		}
		if(mark[i+1])
		{
			sum[root(i+1)]+=sum[root(i)];
			par[root(i)]=root(i+1);
			s.erase(sum[root(i+1)]);
			
		}
		s.insert(sum[root(i)]);
		auto x=s.end();
		x--;
		ans.push(*x);
	}
	while(ans.size())cout<<ans.top()<<"\n",ans.pop();
	return 0;
}