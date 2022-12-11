#include<bits/stdc++.h>
using namespace std;

const int maxn=300111;
int n,p[maxn],q[maxn],t[maxn],pp[maxn];

int a[1100111],b[1100111];
#define ls (t<<1)
#define rs ((t<<1)|1)
void pull(int t)
{
	a[t]=a[ls]+a[rs];
	b[t]=max(b[ls]+a[rs],b[rs]);
}
void add(int p,int v,int tl,int tr,int t)
{
	if(tl==tr)
	{
		a[t]+=v;
		return;
	}
	int mid=(tl+tr)/2;
	if(p<=mid)add(p,v,tl,mid,ls);
	else add(p,v,mid+1,tr,rs);
	pull(t);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)pp[p[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",q+i);
	int cur=n;
	add(pp[n],1,1,n,1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",cur);
		if(i==n)break;
		add(q[i],-1,1,n,1);
		while(max(a[1],b[1])==0)
		{
			cur--;
			add(pp[cur],1,1,n,1);
		}
	}
	return 0;
}