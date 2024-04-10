#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MAX=(1<<30);
const LL N=100005;
LL n,q;
struct qq
{
	LL l,r;
	LL s1,s2;
	LL c,sum;//   
	LL a[4];
}tr[N*2];LL num;
LL a[N];
void renovate (LL *a,LL x,LL y)
{
	a[0]=max(a[0],x+y-abs(x)-abs(y));
	a[1]=max(a[1],x-y-abs(x)-abs(y));
	a[2]=max(a[2],y-x-abs(x)-abs(y));
	a[3]=max(a[3],-x-y-abs(x)-abs(y));
} 
void update (LL now)
{
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL x=a[tr[s1].r],y=a[tr[s2].l];
	tr[now].sum=tr[s1].sum+tr[s2].sum;
	for (LL u=0;u<4;u++)	tr[now].a[u]=max(tr[s1].a[u],tr[s2].a[u]);
	renovate(tr[now].a,x,y);
}
void bt (LL l,LL r)
{
	LL  A=++num;
	tr[A].l=l;tr[A].r=r;
	if (l==r)	
	{
		tr[A].c=a[l];
		tr[A].sum=abs(a[l]);
		memset(tr[A].a,-63,sizeof(tr[A].a));
		return ;
	}
	LL mid=(l+r)>>1;
	tr[A].s1=num+1;bt(l,mid);
	tr[A].s2=num+1;bt(mid+1,r);
	update(A);
}
void change (LL now,LL x)
{
	if (tr[now].l==tr[now].r)	{tr[now].c=a[tr[now].l];tr[now].sum=abs(a[tr[now].l]);return ;}
	LL mid=(tr[now].l+tr[now].r)>>1;
	LL s1=tr[now].s1,s2=tr[now].s2;
	if (x<=mid) change(s1,x);
	else change(s2,x);
	update(now);
}
LL ans[4];
void get (LL now,LL l,LL r)
{
	if (tr[now].l==l&&tr[now].r==r)
	{
		for (LL u=0;u<4;u++)	ans[u]=max(ans[u],tr[now].a[u]);
		return ;
	}
	LL s1=tr[now].s1,s2=tr[now].s2;
	LL mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) get(s1,l,r);
	else if (l>mid) get(s2,l,r);
	else
	{
		get(s1,l,mid);
		get(s2,mid+1,r);
		LL x=a[tr[s1].r],y=a[tr[s2].l];
		renovate(ans,x,y);
	}
}
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)	scanf("%I64d",&a[u]);
	n--;for (LL u=1;u<=n;u++)	a[u]=a[u]-a[u+1];
	bt(1,n);
	scanf("%I64d",&q);
	for (LL u=1;u<=q;u++)
	{
		LL op,l,r,x;
		scanf("%I64d%I64d%I64d%I64d",&op,&l,&r,&x);
		if (op==2)// 
		{
			if (l!=1) 
			{
				a[l-1]-=x;
				change(1,l-1);
			}
			if (r<=n)	{a[r]+=x;change(1,r);}
		}
		else
		{
			memset(ans,-63,sizeof(ans));
			get(1,max(1LL,l-1),min(n,r));
			LL lalal=ans[0];
			lalal=max(lalal,ans[1]-2*x);
			lalal=max(lalal,ans[2]+2*x);
			lalal=max(lalal,ans[3]);
			/*for (LL j=0;j<4;j++) printf("%I64d ",ans[j]);*/
			printf("%I64d\n",tr[1].sum+lalal);
		}
		/*for (LL i=1;i<=num;i++)
		{
			printf("l:%I64d r:%I64d c:%I64d sum:%I64d\n",tr[i].l,tr[i].r,tr[i].c,tr[i].sum);
			for (LL j=0;j<4;j++) printf("%I64d ",tr[i].a[j]);
			printf("\n");
		}*/
	}
	return 0;
}