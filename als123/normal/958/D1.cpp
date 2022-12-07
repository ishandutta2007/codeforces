#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=200005;
int n;
struct qq
{
	int x,c;
	int id;
}s[N];
bool cmp (qq x,qq y){return x.x*y.c<y.x*x.c;}
int f[N];
int ans[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x;
		char ch=getchar();
		while (ch!='(') ch=getchar();
		scanf("%d",&x);s[u].x+=x;
		ch=getchar();
		while (ch!='+') ch=getchar();
		scanf("%d",&x);s[u].x+=x;
		while (ch!=')') ch=getchar();
		while (ch!='/') ch=getchar();
		scanf("%d",&s[u].c);
		s[u].id=u;
	}
	sort(s+1,s+1+n,cmp);
	for (int u=1;u<=n;u++)
	{
		qq x=s[u],y=s[u-1];
		if (x.x*y.c==y.x*x.c)	f[u]=f[u-1];
		f[u]++;
	}
	for (int u=n;u>=1;u--)
	{
		qq x=s[u],y=s[u-1];
		if (x.x*y.c==y.x*x.c)	f[u-1]=max(f[u-1],f[u]);
		ans[s[u].id]=f[u];
	}
	for (int u=1;u<=n;u++) printf("%d ",ans[u]);
	return 0;
}