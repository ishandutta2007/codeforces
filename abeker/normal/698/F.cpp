#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N;
int p[MAXN];
int prime[MAXN];
int rad[MAXN], large[MAXN];
int fact[MAXN];
int group[MAXN];
vector <int> nums[MAXN];
int aux[MAXN], inv[MAXN];
vector <int> curr[MAXN];
int occ[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", p + i);
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

void add(int x, int where) {
	nums[where].push_back(x);
	group[x] = where;
}

int calc(int x) {
	vector <int> all;
	for (auto it : nums[x]) {
		int a = large[it];
		if (p[it]) {
			if (rad[it] != rad[p[it]]) 
				return 0;
			if (group[p[it]] != x) 
				return 0;
			int b = large[p[it]];
			if (aux[a] && aux[a] != b) 
				return 0;
			aux[a] = b;
			if (inv[b] && inv[b] != a)
				return 0;
			inv[b] = a;
		}
		curr[a].push_back(it);
		all.push_back(a);
	}
	
	int res = 1, cnt = 0;
	for (auto it : all) {
		if (curr[it].empty())
			continue;
		cnt += !aux[it];
		vector <int> todo;
		for (; !curr[it].empty(); curr[it].pop_back()) {
			int tmp = curr[it].back();
			if (!p[tmp]) {
				res = mul(res, ++occ[rad[tmp]]);
				todo.push_back(rad[tmp]);
			}
		}
		for (auto tmp : todo)
			occ[tmp] = 0;
	}
	
	return mul(res, fact[cnt]);
}

int solve() {
	fact[0] = 1;
	for (int i = 1; i <= N; i++)
		fact[i] = mul(fact[i - 1], i);
		
	for (int i = 2; i <= N; i++)
		if (!prime[i])
			for (int j = i; j <= N; j += i)
				if (!prime[j])
					prime[j] = i;
	
	for (int i = 1; i <= N; i++) {
		int x = i;
		rad[i] = 1;
		large[i] = i > 1 ? 1 : N;
		while (x > 1) {
			int t = prime[x];
			while (!(x % t))
				x /= t;
			if ((ll)t * t <= N)
				rad[i] *= t;
			else
				large[i] = t;
		}
		add(i, N / large[i]);
	}
	large[1]++;
	
	int sol = 1;
	for (int i = 1; i <= N; i++)
		sol = mul(sol, calc(i));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}