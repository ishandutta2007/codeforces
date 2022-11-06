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
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };

vector<string> a[4];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(t, 0, 4) {
        a[t].resize(n);
        rep(i, 0, n) {
            cin >> a[t][i];
        }
    }

    sort(a, a + 4);
    int ans = 1e9;
    do {
        int c = 0;
        rep(t, 0, 4) {
            rep(i, 0, n) {
                rep(j, 0, n) {
                    if (t == 0 || t == 3) {
                        if (a[t][i][j] != (i + j) % 2 + '0') {
                            c++;
                        }
                    } else {
                        if (a[t][i][j] == (i + j) % 2 + '0') {
                            c++;
                        }
                    }
                }
            }
        }
        ans = min(ans, c);
    } while (next_permutation(a, a + 4));
    cout << ans;
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