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
const LL INF = 1e18 + 9LL;

int main(){
	int test;
	scanf("%d", &test);
	
	while(test--){
		int s, a, b, c;
		scanf("%d %d %d %d", &s, &a, &b, &c);
		printf("%lld\n", 1LL * s / (1LL * c * a) * b + s / c);
	}

	return 0;
}