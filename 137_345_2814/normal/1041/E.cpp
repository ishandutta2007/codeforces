#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{
	int v,id;
}ed[10001];
bool cmp(edge a,edge b)
{
	return a.v<b.v;
}
int n,a,b,ans[2001],u[2001],sid[2001];
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>b)a^=b^=a^=b;
		if(b<n||a==b)
		{
			printf("NO\n");
			return 0;
		}
		ed[i].id=i;
		ed[i].v=a;
	}
	sort(ed+1,ed+n,cmp);ans[n]=n;
	for(int i=1;i<n;i++)
	{
		sid[ed[i].id]=i;
		if(ed[i].v!=ed[i-1].v)
		{
			ans[i]=ed[i].v;
			u[ed[i].v]=1;
		}
		else
		{
			int fg=0;
			for(int j=1;j<ed[i].v;j++)
			if(!u[j])
			{
				ans[i]=j,u[j]=1,fg=1;
				break;
			}
			if(!fg)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<n;i++) 
	printf("%d %d\n",ans[sid[i]],ans[sid[i]+1]);
}