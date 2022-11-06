#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
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

vector<int> ds[8888];
int16_t lcp[8010][8010];
char lenxc[8888];

char lenx(int x) {
    char res = 0;
    do {
        x /= 10;
        res++;
    } while (x);
    return res;
}

int d[8888];

#define eq(l1, l2, len) (lcp[l1][l2] >= len)

void solve(istream& cin, ostream& cout) {
    rep(i, 1, 8888) {
        for (int j = i + i; j < 8888; j += i) {
            ds[j].push_back(i);
        }
        lenxc[i] = lenx(i);
    }
    string s;
    cin >> s;
    int n = s.size();

    repr(i, n, 0) {
        repr(j, n, 0) {
            if (s[i] == s[j]) {
                lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }
    }

    rep(i, 0, n) {
        d[i + 1] = 1 + i + 1;
        rep(j, 1, i + 2) {
            int dij1 = d[i - j + 1];
            d[i + 1] = min(d[i + 1], dij1 + 1 + j);
            int cs = 0;
            for (int dv : ds[j]) {
                if (eq(i - j + 1, i - j + 1 + dv, j - dv)) {
                    d[i + 1] = min(d[i + 1], dij1 + lenxc[j / dv] + dv);
                    cs++;
                    if (cs > 1) {
                        break;
                    }
                }
            }
        }
    }

//    rep(i, 0, n + 1) {
//        cout << d[i] << " ";
//    }
//    cout << endl;

    cout << d[n];
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
}//ucfkxz