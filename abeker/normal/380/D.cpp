#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int MOD = 1000000007;

int N;
int a[MAXN];
int fact[MAXN], inv[MAXN];
int nxt[MAXN], prev[MAXN];
vector <pii> V;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

inline int add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	else if (x < 0) x += MOD;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pow(int x, int y) {
	int res = 1;
	for (; y; y >>= 1) {
		if (y & 1) res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int choose(int n, int k) {
	if (n < k) return 0;
	return mul(fact[n], mul(inv[k], inv[n - k]));
}

int calc(int lo, int hi) {
	int res = pow(2, max(V[0].first - 2, 0));
	for (int i = 1; i < V.size(); i++) {
		if (lo < 1 || hi > N) return 0;
		if (V[i].second == prev[lo - 1]) {
			int tot = V[i].first - V[i - 1].first - 1;
			int left = lo - prev[lo - 1] - 1;
			res = mul(res, choose(tot, left));
			lo = prev[lo - 1];
			hi += tot - left;
			continue;
		}
		if (V[i].second == nxt[hi + 1]) {
			int tot = V[i].first - V[i - 1].first - 1;
			int right = nxt[hi + 1] - hi - 1;
			res = mul(res, choose(tot, right));
			lo -= tot - right;
			hi = nxt[hi + 1];
			continue;
		}
		return 0;
	}
	
	return mul(res, choose(N - hi + lo - 1, lo - 1));
}

int solve() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = pow(fact[i], MOD - 2);
	}
	
	for (int i = 1; i <= N; i++) {
		prev[i] = prev[i - 1];
		if (a[i]) prev[i] = i;
	}
	
	nxt[N + 1] = N + 1;
	for (int i = N; i; i--) {
		nxt[i] = nxt[i + 1];
		if (a[i]) nxt[i] = i;
	}
	
	for (int i = 1; i <= N; i++)
		if (a[i]) V.push_back(pii(a[i], i));
	sort(V.begin(), V.end());
	
	if (V.empty()) return pow(2, N - 1);
	
	int tmp = V[0].first, pos = V[0].second;
	int sol = calc(pos - tmp + 1, pos);
	if (tmp > 1) add(sol, calc(pos, pos + tmp - 1));
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}