#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int t,n,K,i,j,a[N],s[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&K);
		for(i=1;i<=n;++i)
			scanf("%d",a+i);
		for(i=1;i<=n;++i)
			if(a[i]==K)
				break;
		if(i>n)
		{
			puts("no");
			continue;
		}
		if(n==1)
		{
			puts("yes");
			continue;
		}
		s[0]=0;
		for(i=1,j=2*n;i<=n;++i)
		{
			s[i]=s[i-1]+(a[i]>=K?1:-1);
			if(i-2>=0)
				j=min(j,s[i-2]);
			if(s[i]-j>0)
				break;
		}
		if(i<=n)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}