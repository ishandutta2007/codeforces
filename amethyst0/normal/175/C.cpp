#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
	
	int n;
	cin >> n;

	vector<pll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].second >> a[i].first;
	}

	sort(all(a));

	int t;
	cin >> t;
	vector<ll> p(t);
	for (int i = 0; i < t; ++i) {
		cin >> p[i];
	}
	p.pb(1e18);

	ll ans = 0;
	int b = 1;
	ll rest = p[0];
	int ptr = 1;
	int pos = 0;
	while (pos < n) {
		if (a[pos].second < rest) {
			ans += a[pos].first * a[pos].second * ll(b);
			rest -= a[pos].second;
			++pos;
			continue;
		}
		ans += a[pos].first * rest * ll(b);
		a[pos].second -= rest;
		++b;
		rest = p[ptr] - p[ptr - 1];
		++ptr;
	}

	cout << ans << "\n";

}