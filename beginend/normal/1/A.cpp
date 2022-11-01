#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

int main()
{
	int n1,m1,a1;
	scanf("%d%d%d",&n1,&m1,&a1);
	ll n=n1,a=a1,m=m1;
	ll ans=((n+a-1)/a)*((m+a-1)/a);
	printf("%I64d",ans);
	return 0;
}