#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j,k,ans,f[20005],mx;
bool isprime(int n)
{
	for(int i=2;i*i<=n;++i)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	/*f[1]=1<<30;
	for(i=2;i<=n;++i)
	{
		f[i]=1<<30;
		for(j=i;j>=2;--j)
			if(j!=i-1)
			{
				for(k=2;j%k;++k);
				f[i]=min(f[i],f[i-j]+j/k);
			}
		mx=max(mx,f[i]);
	}
	printf("%d\n",mx);*/
	if(n==2)
		printf("1");
	else if(n%2==0)
		printf("2");
	else if(isprime(n))
		printf("1");
	else if(isprime(n-2))
		printf("2");
	else
		printf("3");
	return 0;
}