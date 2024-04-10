#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e3 + 5;
const int MOD = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int N, M;
int s[MAXN];
int f[MAXN], h[MAXN];
vector <int> cows[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", s + i);
		s[i]--;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", f + i, h + i);
		f[i]--;
	}
}

pii calc(int pos) {
	vector <int> lft(N, 0), rig(N, 0);
	for (int i = 0; i < pos; i++)
		lft[s[i]]++;
	for (int i = pos; i < N; i++)
		rig[s[i]]++;
	
	int sum = 0, ways = 1;
	for (int i = 0; i < N; i++) {
		int lhs = 0, rhs = 0, both = 0;
		for (auto it : cows[i]) {
			if (it <= lft[i])
				lhs++;
			if (it <= rig[i])
				rhs++;
			if (it <= lft[i] && it <= rig[i])
				both++;
		}
		if (pos && s[pos - 1] == i) {
			bool ok = false;
			for (auto it : cows[i])
				if (it == lft[i]) {
					ok = true;
					break;
				}
			if (!ok)
				return {-1, 0};
			int tmp = rhs - (lft[i] <= rig[i]);
			if (tmp) {
				sum += 2;
				ways = mul(ways, tmp);
			}
			else
				sum++;
		}
		else {
			int two = lhs * rhs - both;
			int one = lhs + rhs;
			if (two) {
				sum += 2;
				ways = mul(ways, two);
			}
			else if (one) {
				sum++;
				ways = mul(ways, one);
			}
		}
	}
	
	if (!sum)
		sum = -1;
		
	return {sum, ways};
}

void solve() {
	for (int i = 0; i < M; i++)
		cows[f[i]].push_back(h[i]);
		
	pii ans = {0, 1};
	for (int i = 0; i <= N; i++) {
		pii tmp = calc(i);
		if (tmp.first < ans.first)
			continue;
		if (tmp.first > ans.first)
			ans.second = 0;
		ans.first = tmp.first;
		ans.second = add(ans.second, tmp.second);
	}
	
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	load();
	solve();
	return 0;
}