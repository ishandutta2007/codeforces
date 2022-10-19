#include<cstdio>
#include<algorithm>
using namespace std;
int n,l1,r1,l2,mod=1,m1=1,cnt,ans=0;
int a[400002],b[400002];
bool cmp(int a,int b)
{
	return a<b? 1:0;
}
int binary_search(int x)
{
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(b[mid]>=x)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<=24;i++)
	{
		mod<<=1,cnt=0;
		for(int j=1;j<=n;j++)b[j]=a[j]%mod;
		sort(b+1,b+n+1,cmp);
		for(int j=1;j<=n;j++)
		{
			l1=binary_search(m1-b[j]),r1=binary_search(mod-b[j]),cnt+=r1-l1;
			l2=binary_search(mod+m1-b[j]),cnt+=n-l2+1;
			if((b[j]<<1)&m1)--cnt;
		}
		cnt>>=1;
		if(cnt&1)ans+=m1;
		m1<<=1;
	}
	printf("%d",ans);
	return 0;
}