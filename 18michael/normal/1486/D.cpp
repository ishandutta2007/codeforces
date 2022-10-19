#include<bits/stdc++.h>
using namespace std;
int n,k,mn,t;
int a[200002],b[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(int x)
{
	mn=t=0;
	for(int i=1;i<=n;++i)b[i]=b[i-1]+(a[i]>=x);
	for(int i=1;i<=n;++i)b[i]=2*b[i]-i;
	for(int i=k;i<=n;++i)mn=min(mn,b[i-k]),t=max(t,b[i]-mn);
	return t>=1;
}
inline int binary_search()
{
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	read(n),read(k);for(int i=1;i<=n;++i)read(a[i]);
	return 0&printf("%d",binary_search());
}