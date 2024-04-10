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

int n, m;
string a[111];

bool check(char r, char g, char b) {
    if (n % 3 == 0) {
        bool ok = true;
        for (int i = 0; i < n / 3; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != r) {
                    ok = false;
                    break;
                }
            }
        }
        for (int i = n / 3; i < n / 3 * 2; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != g) {
                    ok = false;
                    break;
                }
            }
        }
        for (int i = n / 3 * 2; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != b) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            return true;
        }
    }
    if (m % 3 == 0) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 3; j++) {
                if (a[i][j] != r) {
                    ok = false;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = m / 3; j < m / 3 * 2; j++) {
                if (a[i][j] != g) {
                    ok = false;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = m / 3 * 2; j < m; j++) {
                if (a[i][j] != b) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

void solve(istream& cin, ostream& cout) {
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
    }
    vector<char> cs = {'R', 'G', 'B'};
    sort(cs.begin(), cs.end());
    do {
        if(check(cs[0], cs[1], cs[2])) {
            cout << "YES";
            return;
        }
    } while (next_permutation(cs.begin(), cs.end()));

    cout << "NO";
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