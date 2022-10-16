#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int a[1111111];
#include<algorithm>
int main()
{
	int n;
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)
		for(ii=i*2;ii<=n;ii+=i)
			a[ii]=i;
	std::sort(a+1,a+n+1);
	for(i=2;i<=n;i++)printf("%d ",a[i]);
	puts("");
	
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/