#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e6 + 5;

int prime[DIM];

void build() {
	int n = DIM - 5;
	for(int i = 2; i <= n ; ++i) prime[i] = 1;

	for(int i = 2; i <= n ; ++i){
			if (!prime[i]) continue ;
			
			for(int j = i * 2; j <= n ; j += i)
				prime[j] = 0;
			
	}
	
	for (int i = 1; i <= n ; ++i) prime[i] += prime[i - 1];
}

void solve() {
	int x;
	scanf("%d", &x);
	int r = sqrt(x);
	printf("%d\n", prime[x] - prime[r] + 1);
}

int main() {
	build();
	int t;
	scanf("%d", &t);
	while (t--) solve();

	return 0;
}