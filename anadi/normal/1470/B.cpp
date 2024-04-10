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

int n;
int in[N];
int cnt[N];

int dv[N];

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);

		int val = 1;
		while(in[i] > 1) {
			int p = dv[in[i]];
			int cnt = 0;
			
			while(in[i] % p == 0)
				in[i] /= p, ++cnt;
			
			if(cnt & 1)
				val *= p;
		}
		
		in[i] = val;
		cnt[val]++;
	}
	
	int zero = 0;
	int sum_zero = 0;
	int rest = 0;

	for(int i = 1; i <= n; ++i) {
		if(cnt[in[i]] == 0)
			continue;

		zero = max(zero, cnt[in[i]]);
		if((cnt[in[i]] & 1) and in[i] > 1)
			rest = max(rest, cnt[in[i]]);
		else
			sum_zero += cnt[in[i]];
		
		cnt[in[i]] = 0;
	}
	
	int q;
	scanf("%d", &q);
	
	while(q--) {
		LL w;
		scanf("%lld", &w);
		
		if(w == 0)
			printf("%d\n", zero);
		else
			printf("%d\n", max(rest, sum_zero));
	}
}

int main() {
	dv[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(dv[i])
			continue;
		
		for(int j = i; j < N; j += i)
			dv[j] = i;
	}
	
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}