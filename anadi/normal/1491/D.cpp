#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const LL INF = 1LL * MOD * MOD;

int main() {
	int q;
	scanf("%d", &q);
	
	while(q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		if(u > v) {
			puts("NO");
			continue;
		}
		
		int ones = 0;
		while(v) {
			int r0 = u & 1, r1 = v & 1;
			ones += r0 - r1;
			
			if(ones < 0)
				break;
			
			u >>= 1;
			v >>= 1;
		}
		
		puts(ones < 0 ? "NO" : "YES");
	}

	return 0;
}