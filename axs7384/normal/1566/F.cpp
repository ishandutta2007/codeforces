#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e12;
const int N=200005;
int posl,posr;
ll f[N][3];
ll a[N];
int n,m,t;
pair<ll,ll> b[N];
inline ll work(int k1,int k2,ll l,ll r)
{
	while (b[posl].first<l)
		++posl;
	int posr=posl;
	while (b[posr].first<=r&&posr<m)
		++posr;
	vector<int> v;
	v.clear();
	multiset<ll> s;
	s.clear();
	for (int i=posl;i<=posr;++i)
		if (b[i].first>l&&b[i].second<r)
		{
			v.push_back(i);
			s.insert(b[i].second);
		}
	if (!v.size())
		return 0;
	ll ans=k2*(r-*s.begin());
	for (int p:v)
	{
		s.erase(s.find(b[p].second));
		if (s.empty())
			ans=min(ans,k1*(b[p].first-l));
		else
			ans=min(ans,k1*(b[p].first-l)+k2*(r-*s.begin()));
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		for (int i=1;i<=m;++i)
			scanf("%lld%lld",&b[i].first,&b[i].second);
		sort(a+1,a+1+n);
		sort(b+1,b+1+m);
		a[0]=-inf;
		a[n+1]=inf;
		b[0]={-inf,-inf};
		b[m+1]={inf,inf};
		posl=1;
		for (int i=1;i<=n;++i)
		{
			f[i][1]=min(work(1,2,a[i-1],a[i])+f[i-1][1],work(2,2,a[i-1],a[i])+f[i-1][2]); 
			f[i][2]=min(work(1,1,a[i-1],a[i])+f[i-1][1],work(2,1,a[i-1],a[i])+f[i-1][2]);
		}
		ll ans=min(f[n][1],f[n][2]);
		if (a[n]<b[m].first)
			ans=min(f[n][1]+(b[m].first-a[n]),f[n][2]+(b[m].first-a[n])*2);
		cout<<ans<<endl;
	}
}