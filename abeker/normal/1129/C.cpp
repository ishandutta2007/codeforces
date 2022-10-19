#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e3 + 5;
const int MOD = 1e9 + 7;

int N;
char a[MAXN];
bool bad[100];
int trie[MAXN * MAXN][2];
int sz = 1;
int ans;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf(" %c", a + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

int insert(int node, int pos) {
	if (!pos)
		return 0;
	int &ref = trie[node][a[pos] - '0'];
	if (ref)
		return insert(ref, pos - 1);
	ref = ++sz;
	insert(ref, pos - 1);
	return pos;
}

void calc(int x) {
	vector <int> dp(x + 10, 0);
	dp[x + 1] = 1;
	for (int i = x; i; i--) {
		int tmp = 0;
		for (int j = 0; j < 4 && i + j <= N; j++) {
			tmp = 2 * tmp + (a[i + j] - '0');
			if (j < 3 || !bad[tmp])
				dp[i] = add(dp[i], dp[i + j + 1]);
		}
	}
	
	int where = insert(0, x);
	for (int i = 1; i <= where; i++) 
		ans = add(ans, dp[i]);
}

void solve() {
	for (auto it : {3, 5, 14, 15})
		bad[it] = true;
		
	for (int i = 1; i <= N; i++) {
		calc(i);
		printf("%d\n", ans);
	}
}

int main() {
	load();
	solve();
	return 0;
}