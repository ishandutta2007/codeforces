#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;

int N, M, K;
ll c[MAXN];
int a[MAXN], b[MAXN];
unordered_map <ll, vector <pii> > v;
int dad[MAXN], rnk[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		scanf("%lld", c + i);
	for (int i = 0; i < M; i++)
		scanf("%d%d", a + i, b + i);
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

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	return true;
}

int calc(vector <pii> e) {
	unordered_set <int> curr;
	for (auto it : e) {
		curr.insert(it.first);
		curr.insert(it.second);
	}
	
	for (auto it : curr) {
		dad[it] = it;
		rnk[it] = 0;
	}
	
	int comps = N;
	for (auto it : e)
		comps -= join(it.first, it.second);
	
	return pot(2, comps);
}

int solve() {
	for (int i = 0; i < M; i++)
		v[c[a[i]] ^ c[b[i]]].push_back({a[i], b[i]});
	
	int sol = mul(add(pot(2, K), -(int)v.size()), pot(2, N)); 
	for (auto it : v)
		sol = add(sol, calc(it.second));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}