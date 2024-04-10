#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N, T;
int a[MAXN], t[MAXN];
vector <pii> tmp;

void load() {
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, t + i);
}

bool check(int k) {
	tmp.clear();
	for (int i = 0; i < N; i++)
		if (a[i] >= k)
			tmp.push_back({t[i], i});
	if (tmp.size() < k)
		return false;
	sort(tmp.begin(), tmp.end());
	long long tot = 0;
	for (int i = 0; i < k; i++)
		tot += tmp[i].first;
	return tot <= T;
}

void solve() {
	int lo = 0, hi = N;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	
	printf("%d\n%d\n", lo, lo);
	check(lo);
	for (int i = 0; i < lo; i++)
		printf("%d ", tmp[i].second + 1);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}