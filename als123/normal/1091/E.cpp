#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=500005;
LL n,sum;
LL d[N];
LL h[N];
LL du[N];
bool cmp (LL x,LL y)	{return x>y;}
LL check (LL x)//:0   :1   :2 
{
	bool tf=false;LL tot=0;
	for (LL u=1;u<=n;u++)
	{
		if (tf==false&&x>=d[u]) 	{tf=true;du[++tot]=x;}
		du[++tot]=d[u];
	}
	if (tf==false) du[++tot]=x;
	h[tot+1]=0;for (LL u=tot;u>=1;u--)	h[u]=h[u+1]+du[u];
	LL i=tot,now=0;
	for (LL u=1;u<=tot;u++)
	{
		i=max(i,u+1);
		while (i>(u+1)&&du[i-1]<=u) i--;
		//(u+1,i)   k
		//[i,tot] du 
		now=now+du[u];
	//	printf("%I64d %I64d %I64d %I64d\n",u,i,now,h[i]);
		if (now>u*(u-1)+(i-(u+1))*u+h[i])
		{
			if (d[u]<=x) return 1;
			else return 2;
		}
	}
	return 0;
}
LL t[N],m;
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++) 
	{
		scanf("%I64d",&d[u]);
		sum=sum+d[u];
	}
	sort(d+1,d+1+n,cmp);
	if (sum&1)
	{
		for (LL u=1;u<=n;u+=2)	t[++m]=u;
	}
	else
	{
		for (LL u=0;u<=n;u+=2) t[++m]=u;
	}
	LL l=1,r=m,L,R;
	LL xx=-1;
	//printf("YES:%I64d\n",check(1));
	while (l<=r)
	{
		LL mid=(l+r)>>1;
		//printf("YES:%I64d %I64d\n",t[mid],check(t[mid]));
		if (check(t[mid])==0)  {xx=mid;break;}
		else if (check(t[mid])==1) r=mid-1;
		else l=mid+1;
	}
	if (xx==-1)	{printf("-1\n");return 0;}
	l=1,r=xx;
	while (l<=r)
	{
		LL mid=(l+r)>>1;
		if (check(t[mid])==0) {L=mid;r=mid-1;}
		else l=mid+1;
	}
	l=xx;r=m;
	while (l<=r)
	{
		LL mid=(l+r)>>1;
		if (check(t[mid])==0) {l=mid+1;R=mid;}
		else r=mid-1;
	}
	for (LL u=L;u<=R;u++) printf("%I64d ",t[u]);
	return 0;
}