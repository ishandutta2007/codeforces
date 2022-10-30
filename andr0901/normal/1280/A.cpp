#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

const int MOD = 1e9 + 7;

void solve() {
	int x;
	string s;
	cin >> x >> s;
	forn (i, 0, sz(s))
		s[i] -= '0';
	int len = s.size();
	forn (i, 0, min(sz(s), x)) {
		//cout << len << " " <<  len - i - 2 << " " <<  (int)s[i] <<"\n";
		//cout << len << " ";
		len = (len + ((1LL * len - i - 1 + MOD) % MOD) * (1LL * s[i] - 1)) % MOD;
		int j = i + 1, mx = sz(s), left = s[i] - 1;
		while (sz(s) < x && left) {
			s += s[j];
			j++;
			if (j == mx) {
				j = i + 1;
				left--;
			}
		}
		/*for (char c : s)
			cout << (char)(c + '0');
		cout << "\n";*/
	}
	cout << len << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}