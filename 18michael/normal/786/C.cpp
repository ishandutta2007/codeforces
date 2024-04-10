#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
int n,sq,sq1,vec_t=0;
int a[100002],t[100002],cnt[100002]={},vec[100002];
inline void clear()
{
	for(int i=1;i<=vec_t;++i)cnt[vec[i]]=0;
	vec_t=0;
}
inline int calc(int x)
{
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(cnt[a[i]])continue;
		if(vec_t==x)++res,clear();
		vec[++vec_t]=a[i],++cnt[a[i]];
	}
	if(vec_t)++res,clear();
	return res;
}
int main()
{
	scanf("%d",&n),sq=sqrt(n*log(n)/log(2)),t[0]=n+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=sq;++i)printf("%d ",calc(i));
	sq1=(n-1)/(sq+1)+1;
	for(int i=1,l,r,mid;i<=sq1;++i)
	{
		l=sq+1,r=t[i-1]-1;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(calc(mid)<=i)r=mid-1;
			else l=mid+1;
		}
		t[i]=l;
	}
	for(int i=sq1;i;--i)
		for(int j=t[i];j<t[i-1];++j)
			printf("%d ",i);
	return 0;
}