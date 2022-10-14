#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

vector<int> a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> pref = a;
	for (int i = 0; i + 2 < n; i++) {
		pref[i + 2] += pref[i];
	}
	vector<ll> suff = a;
	for (int i = n - 1; i >= 2; i--) {
		suff[i - 2] += suff[i];
	}

	ll ans = pref[n - 1];
	for (int i = 0; i + 1 < n; i++) {
		ans = max(ans, pref[i] + suff[i + 1]);
	}
	cout << ans;
	return 0;
}