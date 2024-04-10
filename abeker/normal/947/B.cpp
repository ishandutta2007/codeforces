#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N;
int v[MAXN], t[MAXN];
ll pref[MAXN];
int cnt[MAXN];
ll part[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", v + i);
	for (int i = 1; i <= N; i++)
		scanf("%d", t + i);
}

void solve() {
	for (int i = 1; i <= N; i++)
		pref[i] = pref[i - 1] + t[i];
	
	pref[N + 1] = 1e18;
	for (int i = 1; i <= N; i++) {
		if (!v[i])
			continue;
		int pos = lower_bound(pref + 1, pref + N + 2, pref[i - 1] + v[i]) - pref;
		cnt[i]++;
		cnt[pos]--;
		part[pos] += (ll)v[i] - pref[pos - 1] + pref[i - 1];
	}
	
	for (int i = 1; i <= N; i++) {
		cnt[i] += cnt[i - 1];
		printf("%lld ", (ll)cnt[i] * t[i] + part[i]);
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}