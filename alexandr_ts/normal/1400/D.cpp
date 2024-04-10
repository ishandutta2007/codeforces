#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 3e3 + 10;

int a[N];
int s1[N], s2[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		fill(s1, s1 + N, 0);
		fill(s2, s2 + N, 0);
		for (int j = i + 2; j < n; ++j) {
			++s2[a[j]];
		}
		ll cur = 0;
		for (int k = i + 1; k < n - 1; ++k) {
			++s1[a[k]];
		  cur += s2[a[k]];	
			--s2[a[k + 1]];
			cur -= s1[a[k + 1]];
			if (a[i] == a[k + 1]) {
				ans += cur;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();	
	}
}