#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
set<int> st[100005];
int n,m,ans,i,j,k,p[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		st[j].insert(k);
		st[k].insert(j);
	}
	for(i=1;i<=n;++i)
		st[i].insert(i);
	int T=80;
	while(T--)
	{
		for(i=1;i<=n;++i)
			p[i]=i;
		random_shuffle(p+1,p+1+n);
		ans=0;
		for(i=1,j=p[1];i<=n;++i)
			if(i<n&&!st[p[i]].count(p[i+1]))
				++ans;
			else
			{
				if(!st[p[i]].count(j)&&j!=p[i-1])
					++ans;
				j=p[i+1];
			}
		if(ans>=m)
		{
			ans=0;
			for(i=1,j=p[1];i<=n&&ans<m;++i)
			if(i<n&&!st[p[i]].count(p[i+1]))
			{
				++ans;
				printf("%d %d\n",p[i],p[i+1]);
			}
			else
			{
				if(!st[p[i]].count(j)&&j!=p[i-1])
				{
					++ans;
					printf("%d %d\n",p[i],j);
				}
				j=p[i+1];
			}
			return 0;
		}
	}
	printf("-1");
	return 0;
}