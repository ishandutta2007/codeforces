#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,d,b,i,j,a[N],s[N],ans;
int main()
{
	scanf("%d%d%d",&n,&d,&b);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	for(i=1,j=n;i<j;++i,--j)
		if(s[min(1ll*n,i+1ll*i*d)]-ans*b>=b&&s[n]-s[max(0ll,j-1ll*i*d-1)]-ans*b>=b)
			++ans;
	printf("%d",n/2-ans);
	return 0;
}