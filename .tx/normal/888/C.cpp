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

string s;
int n;

bool is_dom(char c, int k) {
    int x = 0;
    rep(i, 0, k - 1) {
        if (s[i] == c) {
            x++;
        }
    }
    rep(i, k - 1, n) {
        if (s[i] == c) {
            x++;
        }
        if (x == 0) {
            return false;
        }
        if (s[i - k + 1] == c) {
            x--;
        }
    }
    return true;
}

void solve(istream& cin, ostream& cout) {
    cin >> s;
    n = s.size();
    int l = 0, r = n;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        bool any = false;
        rep(i, 0, 26) {
            if (is_dom(char(i + 'a'), m)) {
                any = true;
                break;
            }
        }
        if (any) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
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