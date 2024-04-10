#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e13+7;
const int N=300005;
int a[N],p[N],v[N],l[N],r[N];
ll t[N*4],tag[N*4];
int n,m;
set<int> s;
inline void build(int x,int l,int r)
{
	tag[x]=-inf;
	if (l==r)
	{
		if (l==0)
			t[x]=0;
		else
			t[x]=-inf;
	}
	else
	{
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		t[x]=max(t[x*2],t[x*2+1]);
	}
}
inline void add(int x,int l,int r,int L,int R,ll y)
{
	t[x]=max(t[x],y);
	if (l==L&&r==R)
	{
		tag[x]=max(tag[x],y);
		return;
	}
	else
	{
		int mid=(l+r)/2;
		if (R<=mid)
		{
			add(x*2,l,mid,L,R,y);
			return;
		}
		if (L>mid)
		{
			add(x*2+1,mid+1,r,L,R,y);
			return;
		}
		add(x*2,l,mid,L,mid,y);
		add(x*2+1,mid+1,r,mid+1,R,y);
	}
}
inline ll ask(int x,int l,int r,int L,int R)
{
	// cout<<x<<' '<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
	if (l==L&&r==R)
		return max(t[x],tag[x]);
	int mid=(l+r)/2;
	if (R<=mid)
		return max(tag[x],ask(x*2,l,mid,L,R));
	if (L>mid)
		return max(tag[x],ask(x*2+1,mid+1,r,L,R));
	return max(tag[x],max(ask(x*2,l,mid,L,mid),ask(x*2+1,mid+1,r,mid+1,R)));
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	for (int i=1;i<=n;++i)
		scanf("%d",&v[i]);
	s.insert(0);
	s.insert(n+1);
	for (int i=1;i<=n;++i)
	{
		auto it=s.lower_bound(p[i]);
		r[p[i]]=*it-1;
		--it;
		l[p[i]]=*it+1;
		s.insert(p[i]);
	}
	// for (int i=1;i<=n;++i)
	// {
	// 	cout<<l[i]<<' '<<r[i]<<endl;
	// }
	build(1,0,n);
	for (int i=1;i<=n;++i)
	{
		// cout<<i<<' '<<ask(1,0,n,l[i]-1,i-1)+v[i]<<endl;
		add(1,0,n,i,r[i],ask(1,0,n,l[i]-1,i-1)+v[i]);
		// for (int j=1;j<=n;++j)
		// 	for (int k=j;k<=n;++k)
		// 		printf("%d %d %lld\n",j,k,ask(1,0,n,j,j));
		// cout<<i<<">>>>"<<endl;
		// printf("%lld ",ask(1,0,n,i,i));
	}
	printf("%lld",ask(1,0,n,n,n));
}