#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int N=100005;
ll a[N];
ll f[N*4],g[N*4];
inline void build(int x,int l,int r)
{
	if (l==r)
	{
		f[x]=g[x]=a[l];
		// cout<<"?"<<x<<' '<<f[x]<<' '<<g[x]<<endl;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	f[x]=max(f[x*2],f[x*2+1]);
	g[x]=min(g[x*2],g[x*2+1]);
}
inline ll mn(int x,int l,int r,int L,int R)
{
	if (l==L&&r==R)
		return g[x];
	int mid=(l+r)/2;
	if (R<=mid)
		return mn(x*2,l,mid,L,R);
	if (L>mid)
		return mn(x*2+1,mid+1,r,L,R);
	return min(mn(x*2,l,mid,L,mid),mn(x*2+1,mid+1,r,mid+1,R));
}
inline ll mx(int x,int l,int r,int L,int R)
{
	if (l==L&&r==R)
		return f[x];
	int mid=(l+r)/2;
	if (R<=mid)
		return mx(x*2,l,mid,L,R);
	if (L>mid)
		return mx(x*2+1,mid+1,r,L,R);
	return max(mx(x*2,l,mid,L,mid),mx(x*2+1,mid+1,r,mid+1,R));
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for (int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		a[i]-=x;
	}
	// for (int i=1;i<=n;++i)
	// 	printf("%d ",a[i]);
	for (int i=1;i<=n;++i)
		a[i]+=a[i-1];
	// for (int i=1;i<=n;++i)
	// 	cout<<a[i]<<endl;
	build(1,1,n);
	for (int i=1,l,r;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		// cout<<a[l-1]<<' '<<a[r]<<endl;
		// cout<<mx(1,1,n,l,r)<<' '<<mn(1,1,n,l,r)<<endl;
		if (a[l-1]!=a[r]||mx(1,1,n,l,r)>a[r])
			puts("-1");
		else
			printf("%lld\n",a[r]-mn(1,1,n,l,r));
	}
	// puts("");
	// for (int i=1;i<=n;++i)
	// 	printf("%d ",a[i]);

	return 0;
}