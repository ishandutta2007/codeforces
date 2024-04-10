#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct fenwick {
	int f[MAXN];
	fenwick() {
		memset(f, 0, sizeof f);
	}
	void update(int x) {
		for (x++; x < MAXN; x += x & -x)
			f[x]++;
	}
	int get(int x) {
		int res = 0;
		for (x++; x; x -= x & -x)
			res += f[x];
		return res;
	}
	int query(int lo, int hi) {
		return get(hi) - get(lo - 1);
	}
};

int N, Q;
int p[MAXN];
ll sol[MAXN];
int l[MAXN], r[MAXN], d[MAXN], u[MAXN];
fenwick inc, dec;
vector <int> I[MAXN], D[MAXN];

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", p + i);
}

ll choose(int n) {
	return (ll)n * (n - 1) / 2;
}

void solve() {
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d%d", l + i, d + i, r + i, u + i);
		sol[i] = choose(N) - choose(l[i] - 1) - choose(N - r[i]) - choose(d[i] - 1) - choose(N - u[i]);		
		I[l[i] - 1].push_back(i);
		D[r[i] + 1].push_back(i);		
	}
	
	for (int i = 1; i <= N; i++) {
		inc.update(p[i]);
		for (auto it : I[i])
			sol[it] += choose(inc.query(1, d[it] - 1)) + choose(inc.query(u[it] + 1, N));
	}
	
	for (int i = N; i; i--) {
		dec.update(p[i]);
		for (auto it : D[i])
			sol[it] += choose(dec.query(1, d[it] - 1)) + choose(dec.query(u[it] + 1, N));
	}
	
	for (int i = 0; i < Q; i++)
		printf("%lld\n", sol[i]);
}

int main() {
	load();
	solve();
	return 0;
}