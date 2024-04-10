#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=300005;
struct qq
{
	int x,id;
}a[N],b[N];
int n;
int ansx[N],ansy[N],d[N],tot;
void modify (int x,int y)
{
	if (b[x].x<a[x].x)	{printf("NO\n");exit(0);}
	if (a[y].x<b[y].x)  {printf("NO1\n");exit(0);}
	int t=min(a[y].x-b[y].x,b[x].x-a[x].x);
	tot++;
	ansx[tot]=a[x].id;ansy[tot]=a[y].id;d[tot]=t;
	a[x].x=a[x].x+t;a[y].x=a[y].x-t;
}
bool cmp (qq x,qq y)	{return x.x<y.x;}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u].x);
		a[u].id=u;
	}
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&b[u].x);
		b[u].id=u;
	}
	sort(a+1,a+1+n,cmp);sort(b+1,b+1+n,cmp);
	int L1=1,L2=1;
	while (true)
	{
		while (L1<=n&&a[L1].x<=b[L1].x) L1++;
		while (L2<=n&&a[L2].x>=b[L2].x) L2++;
		if (L1>n||L2>n) break;
		if (L1<L2)	{printf("NO\n");return 0;}
		modify(L2,L1);
	}
	if (L1<=n||L2<=n)	{printf("NO\n");return 0;}
	printf("YES\n%d\n",tot);
	for (int u=1;u<=tot;u++) printf("%d %d %d\n",ansx[u],ansy[u],d[u]);
	return 0;
}