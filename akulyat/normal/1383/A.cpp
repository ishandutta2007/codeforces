#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;
string a, b;


void solve() {
	cin >> n;
	cin >> a >> b;	

	vector<vector<ll>> cnt(20, vector<ll>(20, 0));
	for (int i = 0; i < n; i++)
		cnt[a[i] - 'a'][b[i] - 'a']++;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (cnt[i][j] && j < i) {
				cout << "-1\n";
				return;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 20; i++) {
		int mn = 20;
		for (int j = 19; j > i; j--)
			if (cnt[i][j])
				mn = j;
		if (mn != 20) {
			ans++;
			for (int u = mn; u < 20; u++) {
				cnt[mn][u] += cnt[i][u];
				cnt[i][u] = 0;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}