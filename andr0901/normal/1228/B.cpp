#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> grid(n + 1, vector <int> (m + 1));
    forn (i, 0, n) {
        int t;
        cin >> t;
        forn (j, 0, t) 
            grid[i][j] = 1;
        grid[i][t] = 2;
    }
    forn (i, 0, m) {
        int t;
        cin >> t;
        forn (j, 0, t) {
            if (grid[j][i] == 2)
                return cout << 0, 0;
            grid[j][i] = 1;
        }
        if (grid[t][i] == 1)
            return cout << 0, 0;
        grid[t][i] = 2;
    }
    int ans = 1;
    const int MOD = 1e9 + 7;
    forn (i, 0, n)
        forn (j, 0, m) 
            if (!grid[i][j])
                ans = (ans * 2) % MOD;
    cout << ans;
    return 0;
}