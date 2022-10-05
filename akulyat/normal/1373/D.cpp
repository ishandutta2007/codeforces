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

ll solve(vector<ll> v, int mm) {
	ll ans = 0;
	ll val, m;
	val = m = 0;
	for (int i = 0; i < n - 1; i += 2) {
		if (!mm) {
			val -= v[i];
			val += v[i + 1];
		} else {
			val += v[i];
			val -= v[i + 1];
		}
		m = min(val, m);
		ans = max(ans, val - m);
		// cout << i << ": " << val << ' ' << m << endl;
	}
	// cout << endl;

	ll sum = 0;
	for (int i = mm; i < v.size(); i += 2)
		sum += v[i];
	return sum + ans;
}

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	
	int mm = 0;
	ll ans = solve(v, mm);
	reverse(v.begin(), v.end());
	if (n & 1)
		mm = 0;
	else
		mm = 1;
	ans = max(ans, solve(v, mm));

	ll ans2 = v.back();
	v.pop_back();
	n--;
	reverse(v.begin(), v.end());


	mm = 1;
	ll ans3 = solve(v, mm);
	reverse(v.begin(), v.end());
	if (n & 1)
		mm = 1;
	else
		mm = 0;
	ans3 = max(ans3, solve(v, mm));
	ans3 += ans2;

	ans = max(ans, ans3);

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