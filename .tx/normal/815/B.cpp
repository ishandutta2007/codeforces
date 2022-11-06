#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 1
using lint = long long;

const int M = 1e9 + 7;

int mpow(int a, int p) {
    int res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = 1LL * res * a % M;
        }
        a = 1LL * a * a % M;
    }
    return res;
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    bool pl = true;
    while (a.size() > 1 && (!pl || a.size() % 4 == 3)) {
        vector<int> b(a.size() - 1);
        rep(i, 0, a.size() - 1) {
            if (pl) {
                b[i] = (a[i] + a[i + 1]) % M;
            } else {
                b[i] = (a[i] - a[i + 1]) % M;
            }
            pl = !pl;
        }
        a = b;
    }

    if (a.size() == 1) {
        cout << (a[0] + M) % M;
        return;
    }

    int c = 1;
    int ans = 0;
    if (a.size() % 4 == 2) {
        n = (a.size() - 2) / 2;
    }
    if (a.size() % 4 == 0) {
        n = (a.size() - 2) / 2;
    }
    if (a.size() % 4 == 1) {
        n = (a.size() - 1) / 2;
    }
    int k = 0;
    for (int i = 0; i < a.size(); i += 2) {
        ans = (ans + 1LL * c * a[i]) % M;
        if (a.size() % 4 == 2) {
            ans = (ans + 1LL * c * a[i + 1]) % M;
        } else if (a.size() % 4 == 0) {
            ans = (ans - 1LL * c * a[i + 1]) % M;
        }
        k++;
        c = 1LL * c * (n - k + 1) % M * mpow(k, M - 2) % M;
    }
    cout << (ans + M) % M;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand(1251851);
    for (int ti = 0; ti < 1000; ti++) {
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