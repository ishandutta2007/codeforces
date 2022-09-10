#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 19LL;

int n;

int main(){
	scanf("%d", &n);
	int res = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; ++j)
			if((i ^ j) <= n && i + j > (i ^ j) && (i ^ j) >= j)
				++res;
	
	printf("%d\n", res);
	return 0;
}