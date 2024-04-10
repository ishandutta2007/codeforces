#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<ll> b(n + 1, -inf);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+')
			cur++;
		else
			cur--;
		if (cur < 0)
			if (b[-cur] == -inf)
				b[-cur] = i;
	}
	// for (auto i : b)
	// 	cout << i << ' ';
	// cout << endl;
	ll ans = 0;
	for (auto p : b)
		if (p != -inf)
			ans += (p + 1);
	ll was = false;
	for (auto p : b)
		if (p == n - 1)
			was = true;
	if (!was || was)
		ans += n;

	cout << ans << '\n';

}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}