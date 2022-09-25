#include<cstdio>
using namespace std;
int n,ls,rs;
char s[1000400];
int main()
{
	scanf("%d%s",&n,s+1);
	for(ls=1;ls<=n;ls++)
	if(s[ls]!=s[ls+1])break;
	for(rs=n;rs>=1;rs--)
	if(s[rs]!=s[rs-1])break;
	if(ls==n)
	printf("%lld\n",1ll*n*(n+1)/2%998244353);
	else
	if(s[1]==s[n])
	printf("%lld\n",1ll*(ls+1)*(n+2-rs)%998244353);
	else
	printf("%d\n",ls+n-rs+2);
}