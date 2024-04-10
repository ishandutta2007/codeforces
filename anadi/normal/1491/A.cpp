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

int n, q;
int in[N];
int ones;

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);
		ones += in[i] == 1;
	}
	
	for(int i = 1; i <= q; ++i) {
		int t, v;
		scanf("%d %d", &t, &v);
		
		if(t == 1) {
			ones -= in[v] == 1;
			in[v] ^= 1;
			ones += in[v] == 1;
		} else {
			puts(ones < v ? "0" : "1");
		}
	}
	
	return 0;
}