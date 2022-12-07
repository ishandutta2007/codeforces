#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
const LL N=100005*5;
LL n,s,q;
LL num=0;
struct qq
{
	LL l,r;
	LL s1,s2;
}tr[N];//
struct qt
{
	LL x,y,last;
	LL z;
}e[100005*30];LL Num,last[N];
void init (LL x,LL y,LL z)
{
	Num++;
	e[Num].x=x;e[Num].y=y;e[Num].z=z;
	e[Num].last=last[x];
	last[x]=Num;
}
void bt (LL o,LL l,LL r)// 
{
	LL a=++num;
	tr[a].l=l;tr[a].r=r;
	if (l==r) 
	{
		if (o==0)
			init(num,l+4*n,0);
		if (o==1)
			init(l+4*n,num,0);
		return ;
	}
	LL mid=(l+r)>>1;
	tr[a].s1=num+1;bt(o,l,mid);
	tr[a].s2=num+1;bt(o,mid+1,r);
	if (o==0) init(a,tr[a].s1,0),init(a,tr[a].s2,0);
	if (o==1) init(tr[a].s1,a,0),init(tr[a].s2,a,0);
}
LL rt0,rt1;
void add (LL o,LL now,LL l,LL r,LL x,LL w)
{
	if (tr[now].l==l&&tr[now].r==r)
	{
		if (o==0)	init(x,now,w);
		else init(now,x,w);
		return ;
	}
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) add(o,s1,l,r,x,w);
	else if (l>mid) add(o,s2,l,r,x,w);
	else add(o,s1,l,mid,x,w),add(o,s2,mid+1,r,x,w);
}
bool in[N];// 
LL f[N];
void SPFA ()
{
	memset(in,false,sizeof(in));
	memset(f,-1,sizeof(f));
	queue<int> q;
	q.push(s+4*n);f[s+4*n]=0;in[s+4*n]=true;
	while (!q.empty())
	{
		LL x=q.front();q.pop();
	/*	printf("%lld %lld\n",x,f[x]);
		system("pause");*/
		for (LL u=last[x];u!=-1;u=e[u].last)
		{
			LL y=e[u].y;
			if (f[y]==-1||f[y]>f[x]+e[u].z)
			{
				f[y]=f[x]+e[u].z;
				if (!in[y])
				{
					in[y]=true;
					q.push(y);
				}
			}
		}
		in[x]=false;
	}
	for (LL u=1+4*n;u<=5*n;u++)
		printf("%lld ",f[u]);
}
int main()
{
	Num=0;memset(last,-1,sizeof(last));
	scanf("%lld%lld%lld",&n,&q,&s);
	rt0=num+1;bt(0,1,n);	
	rt1=num+1;bt(1,1,n);
	for (LL u=1;u<=q;u++)
	{
		LL op;
		scanf("%lld",&op);
		if (op==1)
		{
			LL x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			init(x+4*n,y+4*n,(LL)z);
		}
		if (op==2)
		{
			LL v,l,r,w;
			scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
			add(0,rt0,l,r,v+4*n,(LL)w);
		}
		if (op==3)
		{
			LL v,l,r,w;
			scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
			add(1,rt1,l,r,v+4*n,(LL)w);
		}
	}
	SPFA();
	return 0;
}