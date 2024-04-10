#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int las[100001],nxt[100001],n,m;
long long sum[100001];
long long ans,tmp;
queue<int> s1,s2;
pair<int,int> v[100001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&v[i].second,&v[i].first),v[i].first*=-1;
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++)v[i].first*=-1;
	for(int i=1;i<=n;i++)
	{
		int tmp=v[i].second;
		if(las[tmp])
		nxt[las[tmp]]=i;
		else
		if(v[i].first>=0)
		{
			sum[v[i].second]+=v[i].first;
			s1.push(i);
			ans+=v[i].first;
		}
		las[tmp]=i;
	}
	tmp=ans;
	for(int i=2;i<=n;i++)
	{
		while(!s1.empty())
		{
			int e=s1.front();s1.pop();
			if(!nxt[e])
			{
				tmp-=sum[v[e].second];
				continue;
			}
			e=nxt[e];
			long long s21=sum[v[e].second]+v[e].first;
			if(s21<0)
			{
				tmp-=sum[v[e].second];
				continue;
			}
			sum[v[e].second]=s21;
			tmp+=v[e].first;
			s2.push(e);
		}
		while(!s2.empty())
		s1.push(s2.front()),s2.pop();
		ans=max(ans,tmp);
	}
	printf("%lld\n",ans);
}