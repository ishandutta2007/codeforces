#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int x;LL n,t,ans=0;
int a[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
bool cmp(int a,int b)
{
	return a<b? 1:0;
}
LL _binary_search(int l,int r,int x)
{
	int mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(a[mid]>=x)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(x),a[i]-=x;
	sort(a+1,a+n+1,cmp),t=_binary_search(1,n,1),ans+=(((n-t+1)*(n-t))>>1);
	for(LL i=1;i<t;++i)ans+=n-_binary_search(t,n,1-a[i])+1;
	printf("%lld",ans);
	return 0;
}