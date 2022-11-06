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
template <typename T> using vc = std::vector<T>;

string a[3][3][3];

void solve(istream& cin, ostream& cout) {
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            rep(k, 0, 3) {
                cin >> a[i][k][j];
            }
        }
    }

    int x, y;
    cin >> x >> y;
    --x; --y;
    x %= 3;
    y %= 3;

    bool any = false;
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            if (a[x][y][i][j] == '.') {
                any = true;
                break;
            }
        }
    }

    if (any) {
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                if (a[x][y][i][j] == '.') {
                    a[x][y][i][j] = '!';
                }
            }
        }
    }

    rep(i, 0, 3) {
        rep(j, 0, 3) {
            rep(k, 0, 3) {
                if (any) {
                    cout << a[i][k][j] << " ";
                } else {
                    rep(t, 0, 3) {
                        char c = a[i][k][j][t];
                        cout << (c == '.' ? '!' : c);
                    }
                    cout << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
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