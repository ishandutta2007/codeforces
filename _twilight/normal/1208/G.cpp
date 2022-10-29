#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 1e6 + 5; 

int num;
int pri[N], mp[N], phi[N];

void Euler(int n) {
	static bitset<N> vis;
	for (int i = 2; i <= n; i++) {
		if (!vis.test(i)) {
			pri[num++] = i;
			mp[i] = i;
			phi[i] = i - 1;
		}
		for (int *p = pri, *_ = pri + num, x; p != _ && (x = i * *p) <= n; p++) {
			vis.set(x);
			mp[x] = *p;
			if (!(i % *p)) {
				phi[x] = phi[i] * *p;
				break;
			} else {
				phi[x] = phi[i] * phi[*p];
			}
		}
	}
}

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	Euler(n);
	ll ans = 1, cmp = 2;
	vector<int> v;
	for (int i = 3; i <= n; i += 2) {
		v.push_back(phi[i]);
	}
	if ((signed) v.size() >= m) {
		sort(v.begin(), v.end());
		for (int i = 0; i < m; i++)
			ans += v[i];
	} else {
		ans = 1e18;
	}
	for (int i = 4; i <= n; i += 2)
		v.push_back(phi[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
		cmp += v[i];
	ans = min(ans, cmp);
	printf("%lld\n", ans);
	return 0;
}