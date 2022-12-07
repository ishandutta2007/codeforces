#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long LL;
const LL MAX=1e15;
const LL N=2005;
LL n;
LL a[N][N];
bool vis[N];
LL f[N][2];
bool b[N][2];
queue<pair<int,int> > q;
bool o[N];
void SPFA ()
{
	memset(b,false,sizeof(b));
	memset(f,127,sizeof(f));
	for (LL u=1;u<=n;u++)
	{
		if (o[u]==false) continue;
		f[u][0]=0;b[u][0]=1;
		q.push(make_pair(u,0));
	}
	while (!q.empty())
	{
		LL i=q.front().first,j=q.front().second;
		for (LL u=1;u<=n;u++)
		{
			if (u==i) continue;
			LL t=min(f[i][j]+(j+1)*a[i][u],MAX);
			if (t<f[u][0])
			{
				f[u][0]=t;
				if (b[u][0]==false)
				{
					b[u][0]=true;
					q.push(make_pair(u,0));
				}
			}
			t=f[i][j];
			if (j==0&&t<f[u][1])
			{
				f[u][1]=t;
				if (b[u][1]==false)
				{
					b[u][1]=true;
					q.push(make_pair(u,1));
				}
			}
		}
		q.pop();b[i][j]=false;
	}
}
int main()
{
	memset(o,false,sizeof(o));
	memset(vis,false,sizeof(vis));
	memset(a,127,sizeof(a));
	LL mn=MAX;
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)
		for (LL i=u+1;i<=n;i++)
		{
			scanf("%I64d",&a[u][i]);
			a[i][u]=a[u][i];
			mn=min(mn,a[u][i]);
		}
	for (LL u=1;u<=n;u++)
		for (LL i=1;i<=n;i++)
			if (u!=i)
			{
				a[u][i]-=mn;
				if (a[u][i]==0) o[u]=o[i]=true;
			}
	SPFA();
	for (LL u=1;u<=n;u++) printf("%I64d\n",f[u][0]+(n-1)*mn);
	return 0;
}