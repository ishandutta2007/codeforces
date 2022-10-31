#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int nxt() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = nxt(), m = nxt();
    vector <vector <char>> a(n, vector <char> (m));
    vector <int> b(n), c(m);
    forn (i, 0, n) {
        forn (j, 0, m) {
            cin >> a[i][j];
            b[i] += (a[i][j] == '*');
            c[j] += (a[i][j] == '*');
        }
    }
    int ans = 0;
    forn (i, 0, n) {
        forn (j, 0, m) {
            int vertical = b[i] - (a[i][j] == '*'), horizontal = c[j] - (a[i][j] == '*');
            ans = max(ans, vertical + horizontal + (a[i][j] == '*'));
        }
    }
    cout << n + m - 1 - ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q = nxt();
    while (q --> 0)
        solve();
    return 0;
}