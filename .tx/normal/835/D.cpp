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

int16_t get_k[5555][5555];
int ans[5555];
int16_t lcp[5555][5555];

char buf[int(1e5)];
size_t bp = 0;

void pri(int x) {
    int len = 0;
    do {
        buf[bp + len] = char('0' + x % 10);
        x /= 10;
        len++;
    } while (x);
    reverse(buf + bp, buf + bp + len);
//    for (int i = 0; i * 2 < len; i++) {
//        swap(buf[bp + i], buf[bp + len - 1 - i]);
//    }
    bp += len;
}

void solve(istream& cin, ostream& cout) {
    string s;
    cin >> s;
    const int n = s.size();

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
    }

    rep(i, 0, n) {
        get_k[i][i] = true;
    }

    ans[0] = n;
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            if (s[l] == s[r] && (l + 1 == r || get_k[l + 1][r - 1])) {
                if (l + 1 == r) {
                    get_k[l][r] = 2;
                    ans[1]++;
                } else {
                    int m = len >> 1;
                    if (lcp[l][r - m + 1] >= m) {
                        int x = get_k[l][l + m - 1];
                        get_k[l][r] = x + 1;
                        ans[x]++;
                    } else {
                        get_k[l][r] = 1;
                        ans[0]++;
                    }
                }
            }
        }
    }

    repr(i, n - 1, 0) {
        ans[i] += ans[i + 1];
    }

//    for (int it = 1; it < 13; it++) {
////        int cr = it & 1;
////        int pr = cr ^ 1;
//        auto& cr = is_k[it & 1];
//        auto& pr = is_k[(it & 1) ^ 1];
////        memset(is_k[cr], 0, sizeof(bool) * 5555 * 5555);
//        auto& ait = ans[it];
//        for (int len = (1 << it); len <= n; len++) {
//            const int clen = len;
//            for (int l = 0; l <= n - clen; l++) {
//                const int r = l + len - 1;
//                const int m = (r - l + 1) >> 1;
//                if (pr[l][l + m - 1] && lcp[l][r - m + 1] >= m) {
//                    cr[l][r] = true;
//                    ait++;
//                } else {
//                    cr[l][r] = false;
//                }
//            }
//        }
//    }

    rep(i, 0, n) {
        pri(ans[i]);
        buf[bp++] = ' ';
//        printf("%d ", ans[i]);
//        cout << ans[i] << " ";
    }
    puts(buf);
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
}//ueomsw