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

ll n, m;
vector<ll> v;
bool viv = false;
string s;

bool al(int pl) {
	if (pl < 0 || pl >= s.size())
		return false;
	return s[pl] == '1';
}

void solve() {
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < min(n, m); i++) {
		string t = s;
		for (int j = 0; j < n; j++)
			if (al(j - 1) ^ al(j + 1))
				t[j] = '1';
		s = t;
	}
	cout << s << '\n';
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