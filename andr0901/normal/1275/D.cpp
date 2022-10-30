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
	int sum = 0;
	bool four = false;
	bool zero = false;
	forn (i, 0, sz(s)) {
		s[i] -= '0';
		sum += s[i];
		if ((s[i] == 0 && zero) || (s[i] != 0 && s[i] % 2 == 0))
			four = true;
		if (s[i] == 0)
			zero = true;
	}
	if (sum % 3 == 0 && zero && four)
		cout << "red";
	else
		cout << "cyan";
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