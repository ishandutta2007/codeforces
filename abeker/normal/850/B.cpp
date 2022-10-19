#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const ll INF = 1e18;

int N, X, Y;
int a[MAXN];
int cnt[MAXN];
ll sum[MAXN];

void load() {
	scanf("%d%d%d", &N, &X, &Y);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

inline int get_cnt(int lo, int hi) {
	if (lo > hi)
		return 0;
	return cnt[min(hi, MAXN - 1)] - cnt[min(lo - 1, MAXN - 1)];
}

inline ll get_sum(int lo, int hi) {
	if (lo > hi)
		return 0;
	return sum[min(hi, MAXN - 1)] - sum[min(lo - 1, MAXN - 1)];
}

ll solve() {
	for (int i = 0; i < N; i++) {
		cnt[a[i]]++;
		sum[a[i]] += a[i];
	}
	
	for (int i = 1; i < MAXN; i++) {
		cnt[i] += cnt[i - 1];
		sum[i] += sum[i - 1];
	}
	
	ll sol = INF;
	for (int i = 2; i < MAXN; i++) {
		ll tot = 0;
		for (int j = i; j < MAXN + i; j += i) {
			int lo = j - min(i - 1, X / Y);
			ll tmp = (ll)get_cnt(lo, j) * j - get_sum(lo, j);
			if (tmp > INF / Y)
				continue;
			tmp *= Y;
			tmp += (ll)get_cnt(j - i + 1, lo - 1) * X;
			tot += tmp;
			if (tot > INF)
				break;
		}
		sol = min(sol, tot);
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}