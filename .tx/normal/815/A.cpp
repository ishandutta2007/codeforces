#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

int a[111][111];

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    bool sw = n > m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (sw) {
                cin >> a[j][i];
            } else {
                cin >> a[i][j];
            }
        }
    }
    if (sw) {
        swap(n, m);
    }
    vector<pair<int, int>> ans;
    rep(i, 0, n) {
        int mn = *min_element(a[i], a[i] + m);
        if (mn > 0) {
            ans.push_back({i, mn});
            rep(j, 0, m) {
                a[i][j] -= mn;
            }
        }
    }

    rep(j, 0, m) {
        int mn = 1e9;
        rep(i, 0, n) {
            mn = min(a[i][j], mn);
        }
        if (mn > 0) {
            ans.push_back({-j - 1, mn});
            rep(i, 0, n) {
                a[i][j] -= mn;
            }
        }
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] != 0) {
                cout << -1;
                return;
            }
        }
    }

    int cop = 0;
    for (auto& i : ans) {
        cop += i.second;
    }

    cout << cop << "\n";
    for (auto& i : ans) {
        rep(j, 0, i.second) {
            if (i.first >= 0) {
                if (sw) {
                    cout << "col " << i.first + 1;
                } else {
                    cout << "row " << i.first + 1;
                }
            } else {
                if (sw) {
                    cout << "row " << -i.first;
                } else {
                    cout << "col " << -i.first;
                }
            }
            cout << "\n";
        }
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}