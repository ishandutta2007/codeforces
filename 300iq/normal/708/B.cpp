#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    int c10, c01;
    cin >> a >> b >> c >> d;
    c10 = c;
    c01 = b;
    int c0 = -1;
    for (int i = 0; i * (ll) (i - 1) / 2 <= a; i++) {
        if (i * (ll) (i - 1) / 2 == a) {
            c0 = i;
            break;
        }
    }
    int c1 = -1;
    for (int i = 0; i * (ll) (i - 1) / 2 <= d; i++) {
        if (i * (ll) (i - 1) / 2 == d) {
            c1 = i;
            break;
        }
    }
    if (c1 != 0 && c0 != 0 && (c1 == -1 || c0 == -1 || ((c0 * (ll) c1) - b != c))) {
        puts("Impossible");
    } else {
        string s1 = "";
        string res = "";
        ll t, w, cnt, need, cur, ans1, ccr, ans;
        for (int f = 0; f < 3; f++) {
            for (int s = 0; s < 3; s++) {
                c0 += f;
                c1 += s;
                s1.clear();
                if (c1 == 0) {c0 -= f; continue;}
                t = c10 / c1;
                w = c10 % c1;
                if (c10 > c1 * c0) {c0 -= f; c1 -= s; continue;}
                cnt = t + (w != 0);
                need = c0 - cnt;
                cur = 0;
                ans = 0;
                for (int i = 0; i < need; i++) {
                    s1 += "0";
                }
                for (int i = 0; i < w; i++) {
                    s1 += "1";
                }
                if (w != 0) s1 += "0";
                for (int i = 0; i < c1 - w; i++) {
                    s1 += "1";
                }
                for (int i = 0; i < t; i++) {
                    s1 += "0";
                }
                ccr = 0;
                ans1 = 0;
                for (auto c : s1) {
                    if (c == '1') {
                        ans1 += ccr;
                        cur++;
                    } else {
                        ccr++;
                        ans += cur;
                    }
                }
                if (c1 * (ll) (c1 - 1) / 2 == d && c0 * (ll) (c0 - 1) / 2 == a && ans == c10 && ans1 == b) {
                    res = s1;
                } 
                c0 -= f;
                c1 -= s;
            }
        }
        swap(c0, c1);
        swap(c01, c10);
        for (int f = 0; f < 3; f++) {
            for (int s = 0; s < 3; s++) {
                c0 += f;
                c1 += s;
                s1.clear();
                if (c1 == 0) {c0 -= f; continue;}
                t = c10 / c1;
                w = c10 % c1;
                if (c10 > c1 * c0) {c0 -= f; c1 -= s; continue;}
                cnt = t + (w != 0);
                need = c0 - cnt;
                ll cur = 0;
                ll ans = 0;
                for (int i = 0; i < need; i++) {
                    s1 += "1";
                }
                for (int i = 0; i < w; i++) {
                    s1 += "0";
                }
                if (w != 0) s1 += "1";
                for (int i = 0; i < c1 - w; i++) {
                    s1 += "0";
                }
                for (int i = 0; i < t; i++) {
                    s1 += "1";
                }
                ccr = 0;
                ans1 = 0;
                for (auto c : s1) {
                    if (c == '0') {
                        ans1 += ccr;
                        cur++;
                    } else {
                        ccr++;
                        ans += cur;
                    }
                }
                if (c1 * (ll) (c1 - 1) / 2 == a && c0 * (ll) (c0 - 1) / 2 == d && ans1 == c10 && ans == c01) {
                    res = s1;
                } 
                c0 -= f;
                c1 -= s;
            }
        }
        if (res == "") {
            puts("Impossible");
        } else {
            puts(res.c_str());
        }
    }
}