#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 5e5 + 10;

int a[N];
int p[N];

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
		p[i + 1] = p[i] + a[i];
	}
	for (int i = 0; i <= n; ++i) {
		p[i] -= i;
	}
	map<int, int> m;
	m[p[0]] = 1;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += m[p[i]];
		m[p[i]]++;	
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