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
string s;
bool viv = false;


void solve() {
	cin >> n >> s;
	int m = 0;
	for (auto i : s)
		m += (i == 'M');
	if (3 * m != n) {
		cout << "NO\n";
		return;
	}
	deque<int> pref, suf;
	for (int i = 0; i < n; i++)	
		if (s[i] == 'T')
			suf.push_back(i);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {
			if (suf.size() && suf.front() == i)
				pref.push_back(suf.front()), suf.pop_front();
		} else {
			if (pref.size() < cnt + 1 || suf.size() < m - cnt) {
				cout << "NO\n";
				return;
			}
			cnt++;
		}
	}
	cout << "YES\n";
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