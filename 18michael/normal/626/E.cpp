#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n,l,r,mid1,mid2,mid=1,len;
int a[200002];
LL pre[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		l=0,r=min(i-1,n+1-i);
		while(l+3<r)
		{
			mid1=((l+r)>>1),mid2=((l+r)>>1)+1;
			if((pre[i]-pre[i-1-mid1]+pre[n]-pre[n-mid1])*(2*mid2+1)<(pre[i]-pre[i-1-mid2]+pre[n]-pre[n-mid2])*(2*mid1+1))l=mid1;
			else r=mid2;
		}
		for(int j=l;j<=r;++j)if(((pre[i]-pre[i-1-j]+pre[n]-pre[n-j])-1LL*a[i]*(2*j+1))*(2*len+1)>((pre[mid]-pre[mid-1-len]+pre[n]-pre[n-len])-1LL*a[mid]*(2*len+1))*(2*j+1))mid=i,len=j;
	}
	printf("%d\n",2*len+1);
	for(int i=mid-len;i<=mid;++i)printf("%d ",a[i]);
	for(int i=n-len+1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}