#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MAX=(1LL<<55);
const LL N=100005;
struct qq
{
	LL x,y,last;
}e[N*2];LL num,last[N];
LL n;
LL a[N],B[N];
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL ans[N];
LL tot[N],son[N];
void dfs (LL x,LL fa)
{
	tot[x]=1;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
		tot[x]+=tot[y];
		if (tot[y]>tot[son[x]]) son[x]=y;
	}
}
LL s1[N*8],s2[N*8],k[N],b[N];//
LL tr[N*8];
LL root;
bool Jud (LL x,LL y,LL pos)//posxy 
{
	return b[x]+k[x]*pos<b[y]+k[y]*pos;
}
void change (LL &now,LL l,LL r,LL x)
{
	if (now==0) 
	{
		now=++num;
		tr[now]=x;
		s1[now]=0;s2[now]=0;
		return ;
	}
	if (l==r)
	{
		if (Jud(x,tr[now],l))
			tr[now]=x;
		return ;
	}
	LL mid=(l+r)>>1;
	if (k[x]<k[tr[now]])//
	{
		if (Jud(x,tr[now],mid))//
			change(s1[now],l,mid,tr[now]),tr[now]=x;
		else
			change(s2[now],mid+1,r,x); 
	}
	else
	{
		if (Jud(x,tr[now],mid))
			change(s2[now],mid+1,r,tr[now]),tr[now]=x;
		else change(s1[now],l,mid,x);
	}
}
LL get (LL x,LL y)
{
	return k[x]*y+b[x];
}
LL get_min (LL now,LL l,LL r,LL x)
{
	if (now==0) return MAX;	 
	LL mid=(l+r)>>1;
	LL ans=get(tr[now],x);
//	printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",now,l,r,tr[now],ans,k[tr[now]],b[tr[now]]);
	if (x<=mid) ans=min(ans,get_min(s1[now],l,mid,x));
	else ans=min(ans,get_min(s2[now],mid+1,r,x));
	return ans; 
}
void Dfs (LL xx,LL x,LL fa)
{
	ans[xx]=min(ans[xx],ans[x]+B[x]*a[xx]);
	change(root,-100000,100000,x);
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		Dfs(xx,y,x);
	}
}
void solve (LL x,LL fa)
{
	if (son[x]==0)// 
	{
		k[x]=B[x];b[x]=0;
		change(root,-100000,100000,x);
		return ;
	}
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa||y==son[x]) continue;
		solve(y,x);
	}
	root=num=0;
	solve(son[x],x);
	//printf("%d\n",x);
	ans[x]=get_min(root,-100000,100000,a[x]);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa||y==son[x]) continue;
		Dfs(x,y,x);
	}
	k[x]=B[x];b[x]=ans[x];
	change(root,-100000,100000,x);
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)	scanf("%I64d",&a[u]);
	for (LL u=1;u<=n;u++) scanf("%I64d",&B[u]);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%I64d%I64d",&x,&y);
		init(x,y);init(y,x);
	}
	dfs(1,0);
//	for (int u=1;u<=n;u++) printf("%I64d %I64d\n",u,son[u]);
	num=0;
	solve(1,0);
	for (LL u=1;u<=n;u++) printf("%I64d ",ans[u]);
	return 0;
}