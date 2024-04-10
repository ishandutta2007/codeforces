#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a[N],fi[N],la[N],t[N*4],f[N];
inline void build(int x,int l,int r)
{
	t[x]=l;
	if (l==r)
		return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
inline int ask(int x,int l,int r,int L,int R)
{
	if (l==L&&r==R)
		return t[x];
	int mid=(l+r)/2;
	if (R<=mid)
		return ask(x*2,l,mid,L,R);
	if (L>mid)
		return ask(x*2+1,mid+1,r,L,R);
	return min(ask(x*2,l,mid,L,mid),ask(x*2+1,mid+1,r,mid+1,R));
}
inline void modify(int x,int l,int r,int p,int y)
{
	if (l==r)
	{
		t[x]=y;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid)
		modify(x*2,l,mid,p,y);
	else
		modify(x*2+1,mid+1,r,p,y);
	t[x]=min(t[x*2],t[x*2+1]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
	{
		la[a[i]]=i;
		if (!fi[a[i]])
			fi[a[i]]=i;
	}
	build(1,0,n);
	for (int i=1;i<=n;++i)
		f[i]=i;
	for (int i=1;i<=n;++i)
		if (la[a[i]]==i)
		{
			f[i]=min(f[i],f[fi[a[i]]-1]+1+(fi[a[i]]!=i));
			if (fi[a[i]]+1<=i-1)
			{
				// cout<<fi[a[i]]+1<<' '<<i-1<<endl;
				f[i]=min(f[i],ask(1,0,n,fi[a[i]]+1,i-1)+1);
			}
			modify(1,0,n,i,f[i]);
			// cout<<i<<' '<<f[i]<<endl;
		}
	cout<<n-f[n];
	return 0;
}