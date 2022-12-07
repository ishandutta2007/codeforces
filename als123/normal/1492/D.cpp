#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
int a,b,k;
int main()
{
	scanf("%d%d%d",&a,&b,&k);
	if (b==1||a==0)
	{
		if (k!=0) {printf("No\n");return 0;}
		printf("Yes\n");
		for (int u=1;u<=b;u++) printf("1");for (int u=1;u<=a;u++) printf("0");printf("\n");
		for (int u=1;u<=b;u++) printf("1");for (int u=1;u<=a;u++) printf("0");
		return 0;
	}
	if (k>a+b-2)	{printf("No\n");return 0;}
	
	printf("Yes\n");
	if (k<=a)
	{
	for (int u=1;u<b;u++) printf("1");
	for (int u=1;u<=a-k;u++) printf("0");
	printf("1");for (int u=1;u<=k;u++) printf("0");
	printf("\n");
	for (int u=1;u<b;u++) printf("1");
	for (int u=1;u<=a-k;u++) printf("0");
	for (int u=1;u<=k;u++) printf("0");printf("1");
	return 0;
	}
	int t=k-a,bb=b-t;
	for (int u=1;u<bb;u++) printf("1");
	printf("1");for (int u=1;u<a;u++) printf("0");
	for (int u=1;u<=t;u++) printf("1");printf("0");
	printf("\n");
	for (int u=1;u<bb;u++) printf("1");
	printf("0");for (int u=1;u<a;u++) printf("0");
	for (int u=1;u<=t;u++) printf("1");printf("1");
	return 0;
}