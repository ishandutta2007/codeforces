#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int SQRT = 320;
const int MOD = 998244353;

int N, K;
int a[MAXN];
int suff[SQRT][2 * MAXN];
int shift[SQRT];
vector <int> pos[MAXN];
int dp[MAXN];
int num[MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline void inc(int &x, int y) {
	x = add(x, y);
}

void modify(int x, int val) {
	num[x] += val;
	if (val == 1)
		inc(suff[x / SQRT][num[x]], dp[x]);
	else
		inc(suff[x / SQRT][num[x] + 1], -dp[x]);
}

void update(int lo, int hi, int val) {
	for (; lo % SQRT && lo < hi; lo++)
		modify(lo, val);
	
	for (; hi % SQRT && hi > lo; hi--)
		modify(hi - 1, val);
	
	lo /= SQRT;
	hi /= SQRT;
	for (int i = lo; i < hi; i++)
		shift[i] += val;
}

int solve() {
	for (int i = 1; i <= N; i++)
		pos[i].push_back(0);
		
	dp[0] = 1;
	inc(suff[0][0], 1);
	for (int i = 1; i <= N; i++) {
		if (pos[a[i]].size() > 1)
			update(pos[a[i]][(int)pos[a[i]].size() - 2], pos[a[i]].back(), -1);
		update(pos[a[i]].back(), i, 1);
		pos[a[i]].push_back(i);
		
		int j = i;
		for (; j % SQRT; j--)
			if (num[j - 1] + shift[(j - 1) / SQRT] <= K)
				inc(dp[i], dp[j - 1]);
		
		for (j = j / SQRT - 1; j >= 0; j--)
			inc(dp[i], add(suff[j][0], -suff[j][min(max(K - shift[j] + 1, 0), 2 * MAXN - 1)]));
		
		inc(suff[i / SQRT][0], dp[i]);
	}
	
	return dp[N];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}