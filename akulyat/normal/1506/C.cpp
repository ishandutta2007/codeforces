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


void solve() {
	string s, t;
	cin >> s >> t;

	int ans = 0;
	for (int l = 1; l <= min(s.size(), t.size()); l++) {
		for (int j = 0; j < s.size() + 1 - l; j++) {
			for (int i = 0; i < t.size() + 1 - l; i++) {
				string s1 = s.substr(j, l);
				string t1 = t.substr(i, l);
				// if (l == 2)
				// 	cout << s1 << ' ' << t1 << endl;
				if (s1 == t1)
					ans = l;
			}
		}
	}
	ans = s.size() + t.size() - 2 * ans;
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