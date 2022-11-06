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

const int N = 1111111;

int f(int x) {
    int res = 1;
    while (x) {
        int c = x % 10;
        x /= 10;
        if (c) {
            res *= c;
        }
    }
    return res;
}

int g[N];
int s[11][N];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;

    rep(i, 1, N) {
        if (i < 10) {
            g[i] = i;
        } else {
            g[i] = g[f(i)];
        }
    }

    rep(i, 1, 10) {
        rep(j, 0, N) {
            s[i][j] = g[j] == i ? 1 : 0;
            if (j) {
                s[i][j] += s[i][j - 1];
            }
        }
    }

    rep(i, 0, n) {
        int l, r, k;
        cin >> l >> r >> k;
        int ans = s[k][r];
        if (l) {
            ans -= s[k][l - 1];
        }
        cout << ans << "\n";
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