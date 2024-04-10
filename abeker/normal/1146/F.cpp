#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

int N;
vector <int> ch[MAXN];
int tot[MAXN], down[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		int p;
		scanf("%d", &p);
		ch[p].push_back(i);
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

void dfs(int x) {
	for (auto it : ch[x])
		dfs(it);
	
	int sz = ch[x].size();
	if (!sz) {
		tot[x] = down[x] = 1;
		return;
	}
	vector <int> pref(sz), suff(sz);
	pref[0] = tot[ch[x][0]];
	for (int i = 1; i < sz; i++)
		pref[i] = mul(pref[i - 1], tot[ch[x][i]]);
	suff[sz - 1] = tot[ch[x][sz - 1]];
	for (int i = sz - 2; i >= 0; i--)
		suff[i] = mul(suff[i + 1], tot[ch[x][i]]);
	
	int one = 0;
	for (int i = 0; i < sz; i++)
		one = add(one, mul(down[ch[x][i]], mul(i ? pref[i - 1] : 1, i < sz - 1 ? suff[i + 1] : 1)));
	
	int all = 1;
	for (auto it : ch[x])
		all = mul(all, add(tot[it], down[it]));
	
	tot[x] = add(all, -one);
	down[x] = add(all, -suff[0]);
}

int solve() {
	dfs(1);
	return tot[1];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}