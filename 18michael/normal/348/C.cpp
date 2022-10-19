#include<bits/stdc++.h>
#define B 316
#define LL long long
using namespace std;
int n,m,q,st_t=0;
LL res;
char c;
int siz[100002],st[100002],to[100002];
LL ans[100002],a[100002],laz[100002];
int cnt[100000/B+2][100002];
bool u[100002];
vector<int> vec[100002];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1,x;i<=m;++i)
	{
		scanf("%d",&siz[i]);
		if(siz[i]>B)st[to[i]=(++st_t)]=i;
		for(int j=0;j<siz[i];++j)scanf("%d",&x),vec[i].push_back(x);
	}
	for(int i=1;i<=st_t;++i)
	{
		for(int j=0;j<siz[st[i]];++j)u[vec[st[i]][j]]=1,ans[st[i]]+=a[vec[st[i]][j]];
		for(int j=1;j<=n;++j)for(int k=0;k<siz[j];++k)cnt[i][j]+=u[vec[j][k]];
		for(int j=0;j<siz[st[i]];++j)u[vec[st[i]][j]]=0;
	}
	for(int x,y;q--;)
	{
		do c=getchar();while(c!='?' && c!='+');
		scanf("%d",&x);
		if(c=='?')
		{
			if(siz[x]>B)printf("%lld\n",ans[x]);
			else
			{
				res=0;
				for(int i=0;i<siz[x];++i)res+=a[vec[x][i]];
				for(int i=1;i<=st_t;++i)res+=cnt[i][x]*laz[st[i]];
				printf("%lld\n",res);
			}
		}
		else
		{
			scanf("%d",&y);
			for(int i=1;i<=st_t;++i)ans[st[i]]+=(LL)cnt[i][x]*y;
			if(siz[x]>B)laz[x]+=y;
			else for(int i=0;i<siz[x];++i)a[vec[x][i]]+=y;
		}
	}
	return 0;
}