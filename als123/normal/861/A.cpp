#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
int c1,c2;
int main()
{
	int n,k;scanf("%d %d",&n,&k);
	LL ans=(LL)n;
	while(ans%2==0) ans/=2,c1++;
	while(ans%5==0) ans/=5,c2++;
	for(int i=1;i<=max(c1,k);i++) ans*=2;
	for(int i=1;i<=max(c2,k);i++) ans*=5;
	printf("%lld",ans);
}