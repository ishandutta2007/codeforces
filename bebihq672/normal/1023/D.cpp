#include<bits/stdc++.h>
using namespace std;
struct Node{
	int mi,l,r;
}p[1010101];
int a[202020];
void build(int now,int l,int r)
{
	p[now].l=l;
	p[now].r=r;
	if(l==r)
	{
		p[now].mi=a[l];
		return;
	}
	int m=(l+r)/2;
	build(now*2,l,m);
	build(now*2+1,m+1,r);
	p[now].mi=min(p[now*2].mi,p[now*2+1].mi);
}
int query(int now,int l,int r)
{
	if(p[now].l==l&&p[now].r==r)
		return p[now].mi;
	int m=(p[now].l+p[now].r)/2;
	if(r<=m)
		return query(now*2,l,r);
	else if(l>m)
		return query(now*2+1,l,r);
	else
		return min(query(now*2,l,m),query(now*2+1,m+1,r));
}
int L[202020],R[202020];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool flag=0;
	for(int i=1;i<=n;i++)
	if(a[i]==q)
	{
		flag=1;
		break;
	}
	if(flag==0)
	{
		bool _0=0;
		for(int i=1;i<=n;i++)
		if(a[i]==0)
		{
			a[i]=q;
			_0=1;
			break;
		}
		if(_0==0)
		{
			puts("NO");
			return 0;
		}
	}
	a[0]=1;
	for(int i=1;i<=n;i++)
	if(a[i]==0)
		a[i]=a[i-1];
	build(1,1,n);
	for(int i=0;i<=q;i++)
		L[i]=n+1;
	for(int i=1;i<=n;i++)
	{
		L[a[i]]=min(L[a[i]],i);
		R[a[i]]=max(R[a[i]],i);
	}
	for(int i=1;i<=q;i++)
	if(L[i]<=R[i])
	{
		if(query(1,L[i],R[i])<i)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}