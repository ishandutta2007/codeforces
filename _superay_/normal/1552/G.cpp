#include <bits/stdc++.h>
using namespace std;
#define popcnt __builtin_popcountll
int n, k, s[15], ns[15];
long long a[15], ps[15], om[15][45];
bool dfs(int i, long long mask) {
	if (i == k) {
		int c = popcnt(mask);
		if (mask != (((1ll << c) - 1) << (n - c))) return false;
		else return true;
	}
	for (int d = 0; d <= ns[i]; d++) {
		if (!dfs(i + 1, (mask & ~a[i]) | om[i][popcnt(mask & a[i]) + d])) return false;
	}
	return true;
}
int main() {
	scanf("%d%d", &n, &k);
	if (n == 1) {
		puts("ACCEPTED");
		return 0;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &s[i]);
		vector<int> vec(s[i]);
		for (int j = 0; j < s[i]; j++) {
			int x;
			scanf("%d", &x);
			x--;
			vec[j] = x;
			a[i] |= (1ll << x);
		}
		for (int j = 1; j <= s[i]; j++) {
			om[i][j] = om[i][j - 1] | (1ll << vec[s[i] - j]);
		}
		if (i) ps[i] = ps[i - 1];
		ps[i] |= a[i];
		ns[i] = popcnt(ps[i] ^ (i ? ps[i - 1] : 0));
	}
	if (ps[k - 1] != (1ll << n) - 1) {
		puts("REJECTED");
		return 0;
	}
	if (!dfs(0, 0ll)) puts("REJECTED");
	else puts("ACCEPTED");
	return 0;
}