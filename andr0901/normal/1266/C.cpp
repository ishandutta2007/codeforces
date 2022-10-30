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

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

void solve() {
	int n, m;
	cin >> n >> m;
	bool transpose = false;
	if (n > m) {
		swap(n, m);
		transpose = true;
	}
	vector <vector <int>> ans(n, vector <int> (m));
	forn (i, 0, m)
		ans[0][i] = i + 2;
	forn (i, 1, n) {
		forn (j, 0, m)
			ans[i][j] = ans[0][j] * (m + i + 1);
	}
	set <int> a;
	forn (i, 0, n) {
		int g = 0;
		forn (j, 0, m)
			g = gcd(g, ans[i][j]);
		a.insert(g);
	}
	forn (j, 0, m) {
		int g = 0;
		forn (i, 0, n)
			g = gcd(g, ans[i][j]);
		a.insert(g);
	}
	if (a.size() < n + m) {
		cout << 0;
		return;
	}
	if (transpose) {
		forn (j, 0, m)
			forn (i, 0, n)
				cout << ans[i][j] << " \n"[i == n - 1];
		return;
	}
	forn (i, 0, n)
		forn (j, 0, m)
			cout << ans[i][j] << " \n"[j == m - 1];
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    while (t --> 0)
        solve();
    return 0;
}