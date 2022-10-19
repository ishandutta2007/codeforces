#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;
const int MAXB = 64;

int N;
int a[MAXN];
int sum[MAXN];
int lst[MAXB];
int prv[MAXN];
int up[MAXN * MAXB];
int cnt[MAXN][2];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		ll x;
		scanf("%lld", &x);
		a[i] = __builtin_popcountll(x);
	}
}

int calc(int x) {
	int res = 0, pref = sum[x];
	for (; x && 2 * a[x] <= pref; x = prv[x]) 
		res += max(cnt[min(x - 1, up[pref - 2 * a[x]])][pref % 2] - (prv[x] ? cnt[prv[x] - 1][pref % 2] : 0), 0);
	return res;
}

ll solve() {
	cnt[0][0]++;
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + a[i];
		for (int j = 0; j < 2; j++)
			cnt[i][j] = cnt[i - 1][j];
		cnt[i][sum[i] % 2]++;
		for (int j = a[i] + 1; j < MAXB; j++)
			prv[i] = max(prv[i], lst[j]);
		lst[a[i]] = i;
	}
	
	for (int i = 1; i <= sum[N]; i++) {
		up[i] = up[i - 1];
		while (up[i] < N && sum[up[i] + 1] <= i)
			up[i]++;
	}
	
	ll sol = 0;
	for (int i = 1; i <= N; i++) 
		sol += calc(i);
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}