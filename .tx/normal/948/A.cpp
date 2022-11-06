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

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] == 'W') {
                rep(k, 0, 4) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        continue;
                    }
                    if (a[x][y] == 'S') {
                        cout << "No";
                        return;
                    }
                }
            }
        }
    }

    cout << "Yes\n";
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] == '.') {
                a[i][j] = 'D';
            }
        }
        cout << a[i] << "\n";
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