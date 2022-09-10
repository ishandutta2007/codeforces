#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--){
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		
		if((y - x) % (a + b) == 0)
			printf("%d\n", (y - x) / (a + b));
		else
			puts("-1");
	}
	return 0;
}