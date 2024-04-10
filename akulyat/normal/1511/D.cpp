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

char c(int ind) {
	return char('a' + ind);
}

string get(int now, int k) {
	if (now == k)
		return "";

	string res;
	res += c(now);
	for (int i = k - 1; i > now + 1; i--)
		res += c(i), res += c(now);


	if (now + 1 != k) {
		res += c(now + 1);
		res += get(now + 1, k);
		res += c(now);
	}

	if (viv)
		cout << "get(" << now << ", " << k << ") = " << res << endl;
	return res;
}

void solve() {
	int k;
	cin >> n >> k;

	auto s = get(0, k);
	if (viv)
		cout << "see: " << s << endl;
	if (s.size() != k * k) {
		cout << "bad" << endl;
		return;
	}

	auto ans = 'a' + s;
	while (ans.size() < n)
		ans += s;
	ans = ans.substr(0, n);

	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}