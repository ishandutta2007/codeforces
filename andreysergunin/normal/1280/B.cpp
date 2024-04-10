#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------


void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }    

    bool onBoarder = false;
    bool fullBoarder = false;
    bool corner = s[0][0] == 'A' || s[0][m - 1] == 'A' || 
            s[n - 1][0] == 'A' || s[n - 1][m - 1] == 'A';

    bool fullLine = false;
    bool full = true;
    bool any = false;

    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            ok &= s[i][j] == 'A';
            full &= s[i][j] == 'A';
            any |= s[i][j] == 'A';

            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                onBoarder |= s[i][j] == 'A';
            }
        }
        if (ok) {
            fullLine = true;
            if (i == 0 || i == n - 1) {
                fullBoarder = true;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= s[i][j] == 'A';
        }
        if (ok) {
            fullLine = true;
            if (j == 0 || j == m - 1) {
                fullBoarder = true;
            }
        }
    }    

    if (full) {
        cout << 0 << endl;
    } else if (fullBoarder) {
        cout << 1 << endl;
    } else if (corner || fullLine) {
        cout << 2 << endl;
    } else if (onBoarder) {
        cout << 3 << endl;
    } else if (any) {
        cout << 4 << endl;
    } else {
        cout << "MORTAL" << endl;
    }
}