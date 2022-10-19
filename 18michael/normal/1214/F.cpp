#include<bits/stdc++.h>
#define LL long long
using namespace std;
int m,n,l,r,mid,t;
int a[200002],b[200002],ida[200002],idb[200002],to[200002];
LL ans[200002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmpa(int x,int y)
{
	return a[x]>a[y]? 1:0;
}
inline bool cmpb(int x,int y)
{
	return b[x]>b[y]? 1:0;
}
inline void add(int l,int r,LL d)
{
	--l,r-=(l/n)*n,l%=n,++l;
	if(r<=n)ans[l]+=d,ans[r]-=d;
	else ans[l]+=d,ans[1]+=d,ans[(r-1)%n+1]-=d;
}
int main()
{
	read(m),read(n);
	for(int i=1;i<=n;++i)read(a[i]),ida[i]=i;
	for(int i=1;i<=n;++i)read(b[i]),idb[i]=i;
	sort(ida+1,ida+n+1,cmpa),sort(idb+1,idb+n+1,cmpb);
	for(int i=1;i<=n;++i)
	{
		t=l=1,r=n;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(a[ida[i]]<b[idb[mid]]-m/2)l=mid+1;
			else r=mid-1;
		}
		add(t+n-i+1,l+n-i+1,m+a[ida[i]]),t=l,r=n;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(a[ida[i]]<b[idb[mid]])l=mid+1;
			else r=mid-1;
		}
		add(t+n-i+1,l+n-i+1,-a[ida[i]]),t=l,r=n;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(a[ida[i]]<=b[idb[mid]]+m/2)l=mid+1;
			else r=mid-1;
		}
		add(t+n-i+1,l+n-i+1,a[ida[i]]),add(l+n-i+1,2*n-i+2,m-a[ida[i]]),t=l=1,r=n;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(b[idb[i]]<a[ida[mid]]-m/2)l=mid+1;
			else r=mid-1;
		}
		add(n-l+i+2,n-t+i+2,b[idb[i]]),t=l,r=n;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(b[idb[i]]<=a[ida[mid]])l=mid+1;
			else r=mid-1;
		}
		add(n-l+i+2,n-t+i+2,-b[idb[i]]),t=l,r=n;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(b[idb[i]]<=a[ida[mid]]+m/2)l=mid+1;
			else r=mid-1;
		}
		add(n-l+i+2,n-t+i+2,b[idb[i]]),add(i+1,n-l+i+2,-b[idb[i]]);
	}
	t=1;for(int i=2;i<=n;++i)if((ans[i]+=ans[i-1])<ans[t])t=i;
	for(int i=1;i<=n;++i)to[ida[i]]=idb[(i+t-2)%n+1];
	printf("%lld\n",ans[t]);for(int i=1;i<=n;++i)printf("%d ",to[i]);
	return 0;
}