#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int N, M, Q;
int w[MAXN];
vector <int> f;
set <int> ones;
int lft[MAXN][10];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", w + i);
}

inline int mul(int x, int y, int mod) {
	return (long long)x * y % mod;
}

int pot(int x, int y, int mod) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x, mod);
		x = mul(x, x, mod);
	}
	return res;
}

int query(int from, int to, int dep) {
	if (f[dep] == 1)
		return 0;
	if (from == to)
		return w[from] % f[dep];
	int nxt = query(from + 1, to, dep + 1);
	return pot(w[from], to - from >= 5 || lft[to][to - from] == INF ? nxt + f[dep + 1] : lft[to][to - from], f[dep]); 
}

int phi(int x) {
	int res = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i)
			continue;
		while (!(x % i))
			x /= i;
		res /= i;
		res *= i - 1;
	}
	if (x > 1) {
		res /= x;
		res *= x - 1;
	}
	return res;
}

int naive(int x, int y) {
	if (y > 30)
		return INF;
	ll res = 1;
	while (y--) {
		res *= x;
		if (res > INF)
			return INF;
	}
	return res;
}

void solve() {
	f.push_back(M);
	while (f.back() > 1)
		f.push_back(phi(f.back()));
	
	for (int i = 1; i <= N; i++)  {
		lft[i][0] = 1;
		for (int j = 1; j <= min(i, 5); j++)
			lft[i][j] = naive(w[i - j + 1], lft[i][j - 1]);
	}
	
	for (int i = 1; i <= N; i++)
		if (w[i] == 1)
			ones.insert(i);
			
	scanf("%d", &Q);
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (w[l] == 1) {
			printf("%d\n", 1 % M);
			continue;
		}
		auto it = ones.lower_bound(l);
		if (it != ones.end())
			r = min(r, *it - 1);
		printf("%d\n", query(l, r, 0));
	}
}

int main() {
	load();
	solve();
	return 0;
}