#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;
const ll INF = 1e18;

int N;
int a[MAXN];
ll pref[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

ll f(int x) {
	vector <int> d;
	d.push_back(0);
	bool ok = false;
	for (int i = 0; i < N; i++) {
		if (x >= a[i] && !ok) {
			d.push_back(x);
			ok = true;
		}
		d.push_back(a[i]);
	}
	if (!ok)
		d.push_back(x);
	
	for (int i = 1; i <= N + 1; i++)
		pref[i] = pref[i - 1] + d[i];
	
	int ptr = N + 1;
	ll res = -INF;
	for (int k = 1; k <= N + 1; k++) {
		while (ptr && d[ptr] <= k)
			ptr--;
		int tmp = max(ptr, k);
		res = max(res, pref[k] - (ll)(tmp - k) * k - pref[N + 1] + pref[tmp] - (ll)k * (k - 1)); 
	}
	
	return res;
}

int find_lft(int pos) {
	int lo = 0, hi = pos;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid) <= 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int find_rig(int pos) {
	int lo = pos + 1, hi = N + 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid) > 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

void bye() {
	puts("-1");
	exit(0);
}

void solve() {
	sort(a, a + N, greater <int> ());
	
	int sum = 0;
	for (int i = 0; i < N; i++)
		if (a[i] % 2)
			sum ^= 1;
			
	int lo = 0, hi = N;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid) < f(mid + 1))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	if (f(lo) > 0)
		bye();
	
	int lft = find_lft(lo);
	int rig = find_rig(lo);
	
	bool ok = false;
	for (int i = lft; i < rig; i++)
		if (i % 2 == sum) {
			printf("%d ", i);
			ok = true;
		}
	if (!ok)
		bye();
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}