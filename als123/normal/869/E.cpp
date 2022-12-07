#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
typedef unsigned long long LL;
const int N=2505;
const LL MOD=10037;
map<pair<pair<int, int>, pair<int, int> >, LL>g;
int n,m,p;
LL f[N][N];
int lb (int x){return x&(-x);}
void change (int x,int y,LL z)
{
	for (int u=x;u<=n;u+=lb(u))
		for (int i=y;i<=m;i+=lb(i))
			f[u][i]=f[u][i]+z;
}
LL get (int x,int y)
{
	LL lalal=0;
	for (int u=x;u>=1;u-=lb(u))
		for (int i=y;i>=1;i-=lb(i))
			lalal=lalal+f[u][i];
	return lalal;
}
int main()
{
	memset(f,0,sizeof(f));
	scanf("%d%d%d",&n,&m,&p);
	LL s=1;
	for (int u=1;u<=p;u++)
	{
		int op,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2);
		if (op==1)// 
		{
			s=s*MOD;
			g[make_pair(make_pair(x1,y1),make_pair(x2,y2))]=s;
			change(x1,y1,s);
			change(x1,y2+1,-s);
			change(x2+1,y1,-s);
			change(x2+1,y2+1,s);
		}
		if (op==2)
		{
			LL ooo=g[make_pair(make_pair(x1,y1),make_pair(x2,y2))];
			change(x1,y1,-ooo);
			change(x1,y2+1,ooo);
			change(x2+1,y1,ooo);
			change(x2+1,y2+1,-ooo);
		}
		if (op==3)
		{
			LL aa=get(x1,y1),bb=get(x2,y2);
			if (aa==bb) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}