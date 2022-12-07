#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=400005;
int n;
struct qq
{
	int a,b,id;
}a[N],b[N];
bool cmp (qq x,qq y)	{return x.a<y.a;}
int fa[N];
int find_fa (int x)	{return fa[x]==x?x:fa[x]=find_fa(fa[x]);}
priority_queue<pair<int,int> > q;
void Merge (int x,int y)
{
//	printf("link:%d %d\n",x,y);
	fa[find_fa(x)]=find_fa(y);
	if (x>n) x-=n;
	else x+=n;
	if (y>n) y-=n;
	else y+=n;
//	printf("link:%d %d\n",x,y);
	fa[find_fa(x)]=find_fa(y);
}
void solve ()
{
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
/*	printf("a:\n");
	for (int u=1;u<=n;u++) printf("%d %d %d\n",a[u].a,a[u].b,a[u].id);
	printf("b:\n");
	for (int u=1;u<=n;u++) printf("%d %d %d\n",b[u].a,b[u].b,b[u].id);*/
	int nn=0;
	while (!q.empty()) q.pop();
	for (int u=1;u<=n;u++)
	{
		while (nn<n&&b[nn+1].a<a[u].a) {nn++;q.push(make_pair(-b[nn].b,b[nn].id));}
		int mn=2*n+1;
		int now=a[u].id;
		while (!q.empty())
		{
			int x=q.top().second,xx=-q.top().first;
			if (xx>a[u].b) break;
			//printf("YES:%d %d\n",now,x);
			Merge(now,x);
			//fa[find_fa(now)]=find_fa(x);
			mn=min(mn,xx);
			q.pop();
		}
		//printf("now:%d %d\n",now,mn);
		
		if (mn!=2*n+1) 
		{
			q.push(make_pair(-mn,now));
		}
	}
}
int tot[N];
bool del[N];
int main()
{
	memset(del,false,sizeof(del));
	scanf("%d",&n);
	for (int u=1;u<=2*n;u++) fa[u]=u;
	for (int u=1;u<=n;u++) 
	{
		a[u].id=u;
		scanf("%d%d",&a[u].a,&a[u].b);
	}
	for (int u=1;u<=n;u++) {b[u]=a[u];b[u].id=a[u].id+n;}
	solve();
	for (int u=1;u<=n;u++)	{a[u].a=2*n-a[u].a+1;a[u].b=2*n-a[u].b+1;}
	for (int u=1;u<=n;u++) {b[u]=a[u];b[u].id=a[u].id+n;}
	solve();
	
	for (int u=1;u<=n;u++) {b[u]=a[u];swap(b[u].a,b[u].b);b[u].id=a[u].id;}
	solve();
	for (int u=1;u<=n;u++)	{a[u].a=2*n-a[u].a+1;a[u].b=2*n-a[u].b+1;}
	for (int u=1;u<=n;u++) {b[u]=a[u];swap(b[u].a,b[u].b);b[u].id=a[u].id;}
	solve();
	
	for (int u=1;u<=n;u++)
	{
		if (find_fa(u)==find_fa(u+n)) 
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int u=1;u<=n;u++)	tot[find_fa(u)]++;
	int ans=0;
	for (int u=1;u<=2*n;u++) if (find_fa(u)==u&&del[u]==false)
	{
		int x=find_fa(u),y;
		if (u<=n) y=find_fa(u+n);
		else y=find_fa(u-n);
		//printf("YES:%d %d\n",x,y);
		if (tot[x]>=tot[y]) 
		{
			del[x]=true;del[y]=true;
			ans=ans+tot[x];
		}
	}
	printf("%d\n",n-ans);
	return 0;
}