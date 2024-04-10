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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    forn (i, 0, n)
        forn (j, 0, m)
            cin >> a[i][j];
    vector <pii> ans;
    vector <vector <int>> b(n, vector <int> (m));
    forn (i, 0, n - 1) {
        forn (j, 0, m - 1) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
                ans.eb(i, j);
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
            }
        }
    }
    forn (i, 0, n)
        forn (j, 0, m)
            if (a[i][j] != b[i][j])
                return cout << "-1", 0;
    cout << sz(ans) << "\n";
    for (pii i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
    return 0;
}