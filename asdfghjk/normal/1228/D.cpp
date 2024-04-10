#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int N=100005,M=600005;
struct node
{
	int u,v;
}e[M];
set<int> st[N];
int n,m,i,j,k,p1,p2,p3,col[N],c[10][10],cnt[10];
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==0)
	{
		printf("-1");
		return 0;
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		e[i]=(node){j,k};
		st[j].insert(k);
		st[k].insert(j);
		p1=j,p2=k;
	}
	for(i=1;i<=n;++i)
		if(!st[i].count(p1))
			col[i]=1;
		else if(!st[i].count(p2))
			col[i]=2;
		else
		{
			if(!p3)
				p3=i;
			col[i]=3;
		}
	for(i=1;i<=n;++i)
		++cnt[col[i]];
	if(cnt[1]==0||cnt[2]==0||cnt[3]==0)
	{
		printf("-1");
		return 0;
	}
	for(i=1;i<=m;++i)
		if(col[e[i].u]==col[e[i].v])
		{
			printf("-1");
			return 0;
		}
		else
			++c[col[e[i].u]][col[e[i].v]],++c[col[e[i].v]][col[e[i].u]];
	if(1ll*cnt[1]*cnt[2]!=c[1][2]||1ll*cnt[1]*cnt[3]!=c[1][3]||1ll*cnt[2]*cnt[3]!=c[2][3])
	{
		printf("-1");
		return 0;
	}
	for(i=1;i<=n;++i)
		printf("%d ",col[i]);
	return 0;
}