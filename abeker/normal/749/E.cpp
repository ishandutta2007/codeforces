#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100005;

struct fenwick {
	ll f[MAXN];
	fenwick() {
		memset(f, 0, sizeof f);
	}
	void update(int x, int val) {
		for (; x < MAXN; x += x & -x)
			f[x] += val;
	}
	ll get(int x) {
		ll res = 0;
		for (; x; x -= x & -x)
			res += f[x];
		return res;
	}
	ll get(int lo, int hi) {
		return get(hi) - get(lo - 1);
	}
};

int N;
int a[MAXN];
fenwick F1, F2;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

ld solve() {
	ll inv = 0, tot = 0;
	for (int i = 1; i <= N; i++) {
		inv += F1.get(a[i] + 1, N);
		F1.update(a[i], 1);
		tot += (F2.get(1, a[i] - 1) - F2.get(a[i] + 1, N)) * (N - i + 1);
		F2.update(a[i], i);
	}
	
	return inv + (ld)tot / ((ll)N * (N + 1));
}

int main() {
	load();
	printf("%.30Lf\n", solve());
	return 0;
}