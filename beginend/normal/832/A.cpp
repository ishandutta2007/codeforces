#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	long long n,k;
	cin>>n>>k;
	if (n/k%2==1) puts("YES");
	else puts("NO");
	return 0;
}