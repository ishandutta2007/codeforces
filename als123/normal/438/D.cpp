#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n,m;
struct qq
{
	LL l,r,s1,s2,c,mx;
}tr[N*2];LL num=0;
LL A[N];
void update (LL now)
{
	LL s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c=tr[s1].c+tr[s2].c;
	tr[now].mx=max(tr[s1].mx,tr[s2].mx);
}
void bt (LL l,LL r)
{
	LL a=++num;
	tr[a].l=l;tr[a].r=r;
	if (l==r)	{tr[a].c=A[l];tr[a].mx=A[l];return ;}
	LL mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
	update(a);
}
LL ask (LL now,LL l,LL r)
{
	if (tr[now].l==l&&tr[now].r==r)	return tr[now].c;
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) return ask(s1,l,r);
	else if (l>mid) return ask(s2,l,r);
	else return ask(s1,l,mid)+ask(s2,mid+1,r);
}
void change (LL now,LL l,LL r,LL x)
{
	if (tr[now].mx<x) return ;
	if (tr[now].l==tr[now].r)	{tr[now].c%=x;tr[now].mx%=x;return ;}
	LL mid=(tr[now].l+tr[now].r)>>1;
	LL s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) change(s1,l,r,x);
	else if (l>mid) change(s2,l,r,x);
	else change(s1,l,mid,x),change(s2,mid+1,r,x);
	update(now);
}
void change1 (LL now,LL l,LL x)
{
	if (tr[now].l==tr[now].r)	{tr[now].c=x;tr[now].mx=x;return ;}
	LL mid=(tr[now].l+tr[now].r)>>1;
	LL s1=tr[now].s1,s2=tr[now].s2;
	if (l<=mid) change1(s1,l,x);
	else change1(s2,l,x);
	update(now);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for (LL u=1;u<=n;u++)	scanf("%lld",&A[u]);
	bt(1,n);
	for (LL u=1;u<=m;u++)
	{
		LL op,l,r,x;
		scanf("%lld",&op);
		if (op==1) 
		{
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",ask(1,l,r));
		}
		if (op==2)
		{
			scanf("%lld%lld%lld",&l,&r,&x);
			change(1,l,r,x);
		}
		if (op==3)
		{
			scanf("%lld%lld",&l,&x);
			change1(1,l,x);
		}
	}
	return 0;
}