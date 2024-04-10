#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod 1000000007LL

int n, k, d;
long long hash[112][2];
bool been[112][2];

long long pd(int a, bool check)
{
	if(a > n)
		return 0;
	if(a == n)
		return (check) ? 1 : 0;
	
	if(been[a][check ? 1 : 0])
		return hash[a][check ? 1 : 0];
	
	been[a][check] = true;
	long long retv = 0LL;
	for(int i = 1; i <= k; i++)
		retv = (retv + pd(a+i, check || (i >= d))) % mod;

	return hash[a][check ? 1 : 0] = retv;
}

int
main(void)
{
	scanf("%d %d %d", &n, &k, &d);
	cout << pd(0, false);
}