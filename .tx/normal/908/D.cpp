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

const lint M = lint(1e9) + 7;

lint mpow(lint a, lint p) {
    lint res = 1;
    for (; p; p >>= 1) {
        if (p & 1) {
            res = res * a % M;
        }
        a = a * a % M;
    }
    return res;
}

lint inv(lint x) {
    return mpow(x, M - 2);
}

void add(lint& a, lint b) {
    a += b;
    while (a >= M) {
        a -= M;
    }
}

lint d[1111][2222];
double dd[1111][2222];

void solve(istream& cin, ostream& cout) {
    int k;
    lint pa, pb;
    cin >> k >> pa >> pb;
    double dpa = 1.0 * pa / (pa + pb);
    double dpb = 1.0 * pb / (pa + pb);
    lint is = inv(pa + pb);
    pa = pa * is % M;
    pb = pb * is % M;

    lint ip1 = inv(pa);
    lint ip2 = inv(pa * pa % M);
    lint ipb = inv(pb);

    d[1][0] = 1;
    dd[1][0] = 1;
    rep(i, 1, k) {
        rep(j, 0, k) {
            add(d[i + 1][j], d[i][j] * pa % M);
            dd[i + 1][j] += dd[i][j] * dpa;
            add(d[i][j + i], d[i][j] * pb % M);
            dd[i][j + i] += dd[i][j] * dpb;
        }
    }

//    rep(i, 0, k + 1) {
//        rep(j, 0, 2 * k + 1) {
//            cout << dd[i][j] << " ";
//        }
//        cout << endl;
//    }

    lint ans = 0;
    double dans = 0;
    rep(i, 1, k) {
        rep(j, k, 2222) {
            add(ans, d[i][j] * j % M);
            dans += dd[i][j] * j;
        }
    }

    rep(j, 0, k) {
        lint x = j + k;
        add(ans, d[k][j] * x % M);
        add(ans, d[k][j] * pa % M * ipb % M);

        dans += dd[k][j] * x + dd[k][j] * dpa / dpb;
    }
    cout << ans;
//    cout << endl << fixed << setprecision(11) << dans << endl;
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