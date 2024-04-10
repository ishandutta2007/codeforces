#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e3 + 5;

int N, K;
int digit[10];
int mask[MAXN];
vector <pii> canAdd[MAXN];
bool dp[MAXN][MAXN];
int ans[MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 7; j++)
			if (s[j] == '1')
				mask[i] |= 1 << j;
	}
}

void init(int d, vector <int> on) {
	for (auto it : on)
		digit[d] |= 1 << it - 1;
}

void solve() {
	init(0, {1, 2, 3, 5, 6, 7});
	init(1, {3, 6});
	init(2, {1, 3, 4, 5, 7});
	init(3, {1, 3, 4, 6, 7});
	init(4, {2, 3, 4, 6});
	init(5, {1, 2, 4, 6, 7});
	init(6, {1, 2, 4, 5, 6, 7});
	init(7, {1, 3, 6});
	init(8, {1, 2, 3, 4, 5, 6, 7});
	init(9, {1, 2, 3, 4, 6, 7});
	
	for (int i = 0; i < N; i++) 
		for (int j = 9; j >= 0; j--) 
			if ((digit[j] & mask[i]) == mask[i])
				canAdd[i].push_back({__builtin_popcount(digit[j] ^ mask[i]), j});
	
	dp[N][0] = true;
	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j <= K; j++)
			for (auto it : canAdd[i])
				if (it.first <= j && dp[i + 1][j - it.first]) {
					dp[i][j] = true;
					break;
				}
	
	for (int i = 0; i < N; i++) {
		bool ok = false;
		for (auto it : canAdd[i])
			if (it.first <= K && dp[i + 1][K - it.first]) {
				ans[i] = it.second;
				K -= it.first;
				ok = true;
				break;
			}
		if (!ok) {
			puts("-1");
			return;
		}
	}
	
	for (int i = 0; i < N; i++)
		printf("%d", ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}