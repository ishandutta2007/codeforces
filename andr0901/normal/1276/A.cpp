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

void solve() {
	string s;
	cin >> s;
	vector <int> ans;
	forn (i, 0, sz(s)) {
		if (i + 1 < sz(s) && s[i] == 't' && s[i + 1] == 'w') {
			if (i + 2 < sz(s) && s[i + 2] == 'o') {
				if (i + 3 < sz(s) && s[i + 3] != 'o')
					ans.pb(i + 2);
				else 
					ans.pb(i + 1);
			}
		}
		if (i - 1 >= 0 && s[i] == 'e' && s[i - 1] == 'n') {
			if (i - 2 >= 0 && s[i - 2] == 'o') {
				if (i - 3 >= 0 && s[i - 3] != 'o')
					ans.pb(i - 2);
				else 
					ans.pb(i - 1);
			}
		}
	}
	sort(all(ans)), ans.erase(unique(all(ans)), ans.end());
	cout << sz(ans) << "\n";
	for (int i : ans)
		cout << i + 1 << " ";
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}