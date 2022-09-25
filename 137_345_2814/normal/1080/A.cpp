#include<cstdio>
#include<algorithm>
using namespace std;
long long a,b;
int main()
{
	scanf("%lld%lld",&a,&b);
	long long ans=((a*2-1)/b+1)+(a*5-1)/b+1+(a*8-1)/b+1;
	printf("%lld\n",ans);
}