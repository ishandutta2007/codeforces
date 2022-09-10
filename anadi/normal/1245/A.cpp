#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--){
		int a, b;
		scanf("%d %d", &a, &b);
		
		if(__gcd(a, b) == 1)
			puts("Finite");
		else
			puts("Infinite");
	}

	return 0;
}