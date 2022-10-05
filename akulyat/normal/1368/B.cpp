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

ll val(vector<ll> &v) {
	ll res = 1;
	for (auto i : v)
		res *= i;
	return res;
}

void solve() {
	cin >> n;
	vector<ll> cnt(10, 1);
	int nxt = 0;
	while (val(cnt) < n) {
		cnt[nxt]++;
		nxt++;
		nxt %= 10;
	}

	string s = "codeforces";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << s[i];
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}