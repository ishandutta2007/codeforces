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
	int n, m;
	cin >> n >> m;
	vector <vector <char>> grid(n, vector <char> (m));
	int a = 0, p = 0;
	forn (i, 0, n)
		forn (j, 0, m)  {
			cin >> grid[i][j];
			if (grid[i][j] == 'A')
				a++;
			else
				p++;
		}
	if (a == 0) {
		cout << "MORTAL\n";
		return;
	}
	if (p == 0) {
		cout << "0\n";
		return;
	}
	bool ok;
	ok = true;
	forn (i, 0, n)
		if (grid[i][0] == 'P')
			ok = false;
	if (ok) {
		cout << "1\n";
		return;
	}
	ok = true;
	forn (i, 0, n)
		if (grid[i][m - 1] == 'P')
			ok = false;
	if (ok) {
		cout << "1\n";
		return;
	}
	ok = true;
	forn (i, 0, m)
		if (grid[0][i] == 'P')
			ok = false;
	if (ok) {
		cout << "1\n";
		return;
	}
	ok = true;
	forn (i, 0, m)
		if (grid[n - 1][i] == 'P')
			ok = false;
	if (ok) {
		cout << "1\n";
		return;
	}
	if (grid[0][0] == 'A' ||
		grid[0][m - 1] == 'A' ||
		grid[n - 1][0] == 'A' ||
		grid[n - 1][m - 1] == 'A') {
		cout << "2\n";
		return;
	}
	forn (i, 0, n) {
		ok = true;
		forn (j, 0, m)
			if (grid[i][j] == 'P')
				ok = false;
		if (ok) {
			cout << "2\n";
			return;
		}
	}
	forn (j, 0, m) {
		ok = true;
		forn (i, 0, n)
			if (grid[i][j] == 'P')
				ok = false;
		if (ok) {
			cout << "2\n";
			return;
		}
	}
	forn (i, 0, n)
		if (grid[i][0] == 'A' || grid[i][m - 1] == 'A') {
			cout << "3\n";
			return;
		}
	forn (i, 0, m)
		if (grid[0][i] == 'A' || grid[n - 1][i] == 'A') {
			cout << "3\n";
			return;
		}
	cout << "4\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}