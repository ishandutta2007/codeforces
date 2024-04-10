#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int LOGN = 17;
const int LOGV = 30;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int N, Q;
int a[MAXN];
int finalPos[MAXN];
ll canProceed[MAXN];
int nxt[MAXN][LOGN];
int sum[MAXN][LOGN];
int suff[MAXN], pot[MAXN];

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

inline ll div_floor(ll x, int y) {
	if (x < 0)
		return -((-x - 1) / y + 1);
	return x / y;
}

int naive(int x, ll val) {
	if (val < 0)
		return x + 1;
	int iter = LOGV;
	for (; x && iter--; x--) {
		val = 2 * val + a[x];
		if (val < 0)
			return x;
		if (val > INF)
			return 1;
	}
	return x;
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
	return (ll)x * y % MOD;
}

int get(int l, int r) {
	return add(suff[l], -mul(suff[r + 1], pot[r - l + 1]));
}

int query(int l, int r) {
	int res = 0;
	for (int i = LOGN - 1; i >= 0; i--)
		if (nxt[r][i] >= l) {
			res = add(res, sum[r][i]);
			r = nxt[r][i];
		}
	return add(mul(res, 2), get(l, r));
}

void solve() {
	pot[0] = 1;
	for (int i = 1; i <= N; i++)
		pot[i] = mul(pot[i - 1], 2);
	for (int i = N; i; i--) 
		suff[i] = add(mul(suff[i + 1], 2), a[i]);
	
	memset(canProceed, -1, sizeof canProceed);
	for (int i = 1; i <= N; i++) {
		if (i > LOGV) {
			ll num = 0;
			for (int j = 0; j < LOGV; j++) 
				num = 2 * num + a[i - j];
			ll lo = div_floor(-num - 1, 1 << LOGV) + 1;
			ll hi = div_floor(-num + INF, 1 << LOGV);
			if (lo == hi && naive(i, lo) == i - LOGV) {
				canProceed[i] = lo;
				num += canProceed[i] << LOGV;
				finalPos[i] = num == canProceed[i - LOGV] ? finalPos[i - LOGV] : naive(i - LOGV, num);
			}				
		}
		nxt[i][0] = max((canProceed[i] ? naive(i, 0) : finalPos[i]) - 1, 0);
		sum[i][0] = get(nxt[i][0] + 1, i);
	}
	
	for (int j = 1; j < LOGN; j++)
		for (int i = 1; i <= N; i++) {
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
			sum[i][j] = add(sum[i][j - 1], sum[nxt[i][j - 1]][j - 1]);
		}
	
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
}

int main() {
	load();
	solve();
	return 0;
}