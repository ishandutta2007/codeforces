#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
LL n,d,m,l=1,r,mid,ans=0;
LL a[100002],pre[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(LL a,LL b)
{
	return a<b? 1:0;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
int main()
{
	read(n),read(d),read(m),r=n;
	for(int i=1,x;i<=n;++i)read(a[i]);
	sort(a+1,a+n+1,cmp);
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(a[mid]>m)r=mid-1;
		else l=mid+1;
	}
	for(int i=1,x;i<=n;++i)a[i]+=a[i-1];
	for(LL i=0;n-i>=l-1 && (i-1)*(d+1)+1<=n;++i)
		ans=max(ans,a[n]-a[n-i]+a[l-1]-a[max(0,(l-1)-(n-((i-1)*(d+1)+1)))]);
	printf("%lld",ans);
	return 0;
}