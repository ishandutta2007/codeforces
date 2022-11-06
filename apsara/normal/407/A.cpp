#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
int gcd(int x,int y)
{
	if(!x)return y;
	if(!y)return x;
	return gcd(y,x%y);
}
bool check(int a,int b)
{
	int c=gcd(a,b);
	for(int i=1;i<=c;i++)
	for(int j=1;j<=c;j++)
	if(i*i+j*j==c*c)
	{
		if(a/c*j==b/c*i)continue;
		puts("YES");
		printf("0 0\n");
		printf("%d %d\n",a/c*i,a/c*j);
		printf("%d %d\n",-b/c*j,b/c*i);
		return true;
	}
	return false;
}
int a,b;
int main()
{
	while(~scanf("%d%d",&a,&b))
	{
		if(!check(a,b))puts("NO");
	}
}