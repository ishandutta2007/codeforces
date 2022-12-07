#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MOD=1e9+7;
const int N=100005;
int n,q;
int a[N];
struct qq
{
	int x,l,id;
}s[N];
bool cmp (qq x,qq y){return x.x<y.x;}
int f[22];
int ans[N];
int Ans=1;
void add (int x)
{
	for (int u=20;u>=0;u--)
		if ((x&(1<<u))!=0)
		{
			if (f[u]==-1)	{f[u]=x;return ;}
			x^=f[u];
		}
	Ans=Ans*2%MOD;
}
bool check (int x)
{
	for (int u=20;u>=0;u--)
		if ((x&(1<<u))!=0)
		{
			if (f[u]==-1) return false;
			x^=f[u];
		}
	return true;
}
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&q);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	for (int u=1;u<=q;u++)	{scanf("%d%d",&s[u].x,&s[u].l);s[u].id=u;}
	sort(s+1,s+1+q,cmp);
	for (int u=1;u<=q;u++)
	{
		for (int i=s[u-1].x+1;i<=s[u].x;i++) add(a[i]);
		if (check(s[u].l))	ans[s[u].id]=Ans;
	}
	for (int u=1;u<=q;u++)
		printf("%d\n",ans[u]);
	return 0;
}