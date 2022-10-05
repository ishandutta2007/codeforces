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
string d;
bool viv = false;

bool check(string s) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += (s[i] == '(');
		cnt -= (s[i] == ')');
		if (cnt < 0)
			return false;
	}
	if (cnt)
		return false;
	return true;
}

void solve() {
	cin >> n;
	cin >> d;

	int cnt0 = 0;
	for (auto i : d)
		cnt0 += (i == '0');

	if (cnt0 & 1) {
		cout << "NO\n";
		return;
	}

	string s(n, '-');
	string t(n, '-');

	int cnt1 = n - cnt0;
	int cnt = 0, z = 0;
	for (int i = 0; i < n; i++) {
		if (2 * cnt < cnt1 && d[i] == '1') { 
			s[i] = t[i] = '(';
			cnt++;
		} else {
			if (d[i] == '1')
				s[i] = t[i] = ')';
			else {
				if (z & 1)
					s[i] = ')', t[i] = '(';
				else
					s[i] = '(', t[i] = ')';
				z ^= 1;
			}
		}
	}
	// cout << s << '\n';
	// cout << t << '\n';
	if (!check(t) || !check(s))  {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << s << '\n';
		cout << t << '\n';
	}
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