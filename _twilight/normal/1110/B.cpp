#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

int n, k;
vector<int> d;

int main() {
	int lst;
	scanf("%d%*d%d%d", &n, &k, &lst);
	ll ans = n;
	for (int i = 2, x; i <= n; i++) {
		scanf("%d", &x);
		d.push_back(x - lst - 1);
		lst = x;
	}
	sort(d.begin(), d.end());
	for (int i = 0; i < n - k; i++) {
		ans += d[i];
	}
	cout << ans << '\n';
	return 0;
}