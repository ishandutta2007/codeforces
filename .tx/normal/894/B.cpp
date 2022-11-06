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

const lint M = int(1e9) + 7;

int a[11][11];

lint mpw(lint a, lint p) {
    lint res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = res * a % M;
        }
        a = a * a % M;
    }
    return res;
}

void solve(istream& cin, ostream& cout) {
//    rep(n, 1, 5) {
//        rep(m, n, 7) {
//            for (int k = -1; k <= 1; k += 2) {
//                int ans = 0;
//                rep(msk, 0, shl(n * m)) {
//                    rep(i, 0, n * m) {
//                        a[i / m][i % m] = hbit(msk, i) * 2 - 1;
//                    }
//
//                    bool allr = true;
//                    rep(i, 0, n) {
//                        int p = 1;
//                        rep(j, 0, m) {
//                            p *= a[i][j];
//                        }
//                        if (p != k) {
//                            allr = false;
//                            break;
//                        }
//                    }
//
//                    bool allc = true;
//                    rep(j, 0, m) {
//                        int p = 1;
//                        rep(i, 0, n) {
//                            p *= a[i][j];
//                        }
//                        if (p != k) {
//                            allc = false;
//                            break;
//                        }
//                    }
//                    if (allr && allc) {
//                        ans++;
//                    }
//                }
//                cout << n << " " << m << " " << k << " " << ans << "\n";
//            }
//        }
//    }
    lint n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    int k;
    cin >> k;
    if (k == -1 && (n % 2 == 0) != (m % 2 == 0)) {
        cout << 0;
        return;
    }
    lint p = ((n - 1) % (M - 1)) * ((m - 1) % (M - 1)) % (M - 1);
    cout << mpw(2, p);
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