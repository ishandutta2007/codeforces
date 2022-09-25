#include <bits/stdc++.h>

using namespace std;

const int MX = 12, MXK = 101;

int cnt[1 << MX], dp[1 << MX][MXK], w[MX];

int main() {
	int n, m, q;
	ignore = scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++) ignore = scanf("%d", w + i);
	
	auto get = []() {
		static char s[MX + 1];
		ignore = scanf(" %s", s);
		int x = 0;
		for (int i = 0; s[i] != 0; i++) {
			x = 2 * x + s[i] - '0';
		}
		return x;
	};
	
	while (m--) cnt[get()]++;
	
	vector<vector<int>> vec(MXK);
	for (int mask = 0; mask < (1 << n); mask++) {
		int s = 0;
		for (int i = 0; i < n; i++) {
			if (((mask >> i) & 1) == 0)
				s += w[n - i - 1];
		}
		
		if (s < MXK) vec[s].push_back(mask);
	}
	
	for (int x = 0; x < (1 << n); x++)
		for (int k = 0, s = 0; k < MXK; k++) {
			for (int y : vec[k])
				s += cnt[x ^ y];
			
			dp[x][k] = s;
		}
	
	while (q--) {
		int x = get(), k;
		ignore = scanf("%d", &k);
		printf("%d\n", dp[x][k]);
	}
	
	return 0;
}