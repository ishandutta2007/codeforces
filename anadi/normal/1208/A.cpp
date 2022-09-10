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
		int a, b, n;
		scanf("%d %d %d", &a, &b, &n);
		n %= 3;
		if(n == 0)
			printf("%d\n", a);
		else if(n == 1)
			printf("%d\n", b);
		else
			printf("%d\n", a ^ b);
	}

	return 0;
}