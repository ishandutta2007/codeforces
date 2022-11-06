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

const int N = int(1e6);
int cd[N + 31];
int dr[N + 31];
int cdr[N + 31];

int sd(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 1, n + 1) {
        for (int j = i; j <= n; j += i) {
            cd[j]++;
        }
    }

    rep(i, 1, N + 1) {
        int s = sd(i);
        if (s <= 9) {
            dr[i] = s;
        } else {
            dr[i] = dr[s];
        }
        if (i <= n) {
            cdr[dr[i]]++;
        }
    }

    lint ans = 0;
    rep(i, 1, n + 1) {
        ans -= cd[i];
        rep(a, 1, 10) {
            rep(b, 1, 10) {
                if (dr[a * b] == dr[i]) {
                    ans += 1LL * cdr[a] * cdr[b];
                }
            }
        }
    }

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
}//wscoav