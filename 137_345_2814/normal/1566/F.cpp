#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200500
#define ll long long
int T,n,m,l,r;
vector<pair<int,int> > t1[N],t2[N];
ll f[N][2],v[N];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++)t1[i].clear(),f[i][0]=f[i][1]=1e17;
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
	sort(v+1,v+n+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		int s1=lower_bound(v+1,v+n+1,l)-v,s2=lower_bound(v+1,v+n+1,r)-v;
		if(s1<s2)continue;
		t1[s1-1].push_back(make_pair(l,r));
	}
	for(int i=0;i<=n;i++)
	{
		t2[i].clear();
		for(int j=0;j<t1[i].size();j++)t1[i][j].first*=-1;
		sort(t1[i].begin(),t1[i].end());
		for(int j=0;j<t1[i].size();j++)t1[i][j].first*=-1;
		int mn=1.1e9;
		for(int j=0;j<t1[i].size();j++)if(t1[i][j].second>=mn)continue;else mn=t1[i][j].second,t2[i].push_back(t1[i][j]);
		if(i)t2[i].push_back(make_pair(v[i],v[i]));
		reverse(t2[i].begin(),t2[i].end());
	}
	t2[0].push_back(make_pair(v[1],v[1]));
	f[1][0]=-t2[0][0].second,f[1][1]=-2ll*t2[0][0].second;
	for(int i=1;i<n;i++)
	{
		t2[i].push_back(make_pair(v[i+1],v[i+1]));
		for(int j=0;j+1<t2[i].size();j++)
		{
			ll nw=min(t2[i][j].first*2-v[i]+f[i][0],t2[i][j].first+v[i]+f[i][1]);
			f[i+1][0]=min(f[i+1][0],nw-t2[i][j+1].second);
			f[i+1][1]=min(f[i+1][1],nw-t2[i][j+1].second*2);
		}
	}
	printf("%lld\n",min(t2[n].back().first*2-v[n]+f[n][0],t2[n].back().first+v[n]+f[n][1]));
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
}