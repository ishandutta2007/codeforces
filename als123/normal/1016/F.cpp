#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=300005;
LL n,m;
struct qq
{
	LL x,y,z,last;
}e[N*2];LL num,last[N];
void init (LL x,LL y,LL z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
LL d[N];
LL son[N][2];
bool tf=false;
void dfs (LL x,LL fa)
{
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		if (son[x][0]==-1) son[x][0]=y;
		else if (son[x][1]==-1) son[x][1]=y;
		else tf=true;
		d[y]=d[x]+e[u].z;
		dfs(y,x);
	}
	if (son[x][0]==-1||son[x][1]==-1) return ;
	//printf("haha:%lld %lld %lld\n",x);
	if (son[son[x][1]][0]!=-1)	swap(son[x][0],son[x][1]);	
	if (son[x][1]==n) swap(son[x][0],son[x][1]);
	if (son[son[x][1]][0]==-1) return ;
	tf=true;
}
LL lalal;
LL ans=0;
void dfs1 (LL x)
{
	if (son[x][0]!=-1) dfs1(son[x][0]);
	//if (son[x][0]!=-1) ans=max(ans,d[son[x][0]]+lalal);
	if (son[x][1]!=-1) 
	{
		ans=max(ans,d[son[x][1]]+lalal);
		ans=max(ans,d[son[x][1]]+d[n]-d[son[x][0]]);
	}
	ans=max(ans,lalal+d[x]);
	//if (son[x][0]!=-1) lalal=max(lalal,d[son[x][0]]+d[n]-2*d[x]);
	if (son[x][1]!=-1) lalal=max(lalal,d[son[x][1]]+d[n]-2*d[x]);
    if (son[x][0]!=-1) lalal=max(lalal,abs(d[n]-d[son[x][0]]));
	//printf("YES:%lld %lld %lld\n",x,lalal,ans);
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld%lld",&n,&m);
	for (LL u=1;u<n;u++)
	{
		LL x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		init(x,y,z);init(y,x,z);
	}
	memset(son,-1,sizeof(son));
	dfs(1,0);
	/*for (LL u=1;u<=n;u++)
		printf("%lld:%lld %lld\n",u,son[u][0],son[u][1]);*/
	if (son[n][0]!=-1)
	{
		if (son[n][1]!=-1)	tf=true;
		if (son[son[n][0]][0]!=-1) tf=true;
	}
//	printf("tf:%d\n",tf);
	if (tf==true)
	{
		while (m--)	printf("%lld\n",d[n]);
		return 0;
	}
	lalal=-d[n];
	dfs1(1);
	while (m--)
	{
		LL x;
		scanf("%lld",&x);
		if (x+ans<=d[n])
			printf("%lld\n",x+ans);
		else printf("%lld\n",d[n]);
	}
	return 0;
}