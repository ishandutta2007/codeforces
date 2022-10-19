#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,l,r;
int a[100002];
inline bool cmp(int a,int b)
{
	return a<b? 1:0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp),l=((n+1)>>1),r=l+1;
		while(l)
		{
			printf("%d ",a[l]),--l;
			if(r<=n)printf("%d ",a[r]),++r;
		}
		puts("");
	}
	return 0;
}