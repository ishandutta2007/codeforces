#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int LMAX = 30;
string dp1[LMAX + 5][1 << 8];
string dp2[LMAX + 5][1 << 8];
string dp3[LMAX + 5][1 << 8];

string sol[1 << 8];

string good[] = {
"!x&x",
"!(x|y|z)",
"!x&!y&z",
"!x&!y",
"!x&!z&y",
"!x&!z",
"!(!y&!z|x|y&z)",
"!(x|y&z)",
"!x&y&z",
"!(!y&z|!z&y|x)",
"!x&z",
"!(!z&y|x)",
"!x&y",
"!(!y&z|x)",
"!x&(y|z)",
"!x",
"!y&!z&x",
"!y&!z",
"!(!x&!z|x&z|y)",
"!(x&z|y)",
"!(!x&!y|x&y|z)",
"!(x&y|z)",
"!(!x&!y|x&y|z)|!x&!y&z",
"!((x|y)&z|x&y)",
"!x&y&z|!y&!z&x",
"!x&y&z|!y&!z",
"!x&z|!y&!z&x",
"!x&z|!y&!z",
"!x&y|!y&!z&x",
"!x&y|!y&!z",
"!x&(y|z)|!y&!z&x",
"!x|!y&!z",
"!y&x&z",
"!(!x&z|!z&x|y)",
"!y&z",
"!(!z&x|y)",
"!x&!z&y|!y&x&z",
"!x&!z|!y&x&z",
"!x&!z&y|!y&z",
"!x&!z|!y&z",
"!x&y&z|!y&x&z",
"!(!x&z|!z&x|y)|!x&y&z",
"!(x&y)&z",
"!(!z&x|y)|!x&z",
"!x&y|!y&x&z",
"!(!y&z|x)|!y&x&z",
"!x&y|!y&z",
"!x|!y&z",
"!y&x",
"!(!x&z|y)",
"!y&(x|z)",
"!y",
"!x&!z&y|!y&x",
"!x&!z|!y&x",
"!x&!z&y|!y&(x|z)",
"!x&!z|!y",
"!x&y&z|!y&x",
"!(!x&z|y)|!x&y&z",
"!x&z|!y&x",
"!x&z|!y",
"!x&y|!y&x",
"!(!x&!y&z|x&y)",
"!x&(y|z)|!y&x",
"!x|!y",
"!z&x&y",
"!(!x&y|!y&x|z)",
"!x&!y&z|!z&x&y",
"!x&!y|!z&x&y",
"!z&y",
"!(!y&x|z)",
"!x&!y&z|!z&y",
"!x&!y|!z&y",
"!x&y&z|!z&x&y",
"!(!x&y|!y&x|z)|!x&y&z",
"!x&z|!z&x&y",
"!(!z&y|x)|!z&x&y",
"!(x&z)&y",
"!(!y&x|z)|!x&y",
"!x&z|!z&y",
"!x|!z&y",
"!z&x",
"!(!x&y|z)",
"!x&!y&z|!z&x",
"!x&!y|!z&x",
"!z&(x|y)",
"!z",
"!x&!y&z|!z&(x|y)",
"!x&!y|!z",
"!x&y&z|!z&x",
"!(!x&y|z)|!x&y&z",
"!x&z|!z&x",
"!(!x&!z&y|x&z)",
"!x&y|!z&x",
"!x&y|!z",
"!x&(y|z)|!z&x",
"!x|!z",
"!y&x&z|!z&x&y",
"!(!x&y|!y&x|z)|!y&x&z",
"!y&z|!z&x&y",
"!(!z&x|y)|!z&x&y",
"!y&x&z|!z&y",
"!(!y&x|z)|!y&x&z",
"!y&z|!z&y",
"!(!y&!z&x|y&z)",
"!x&y&z|!y&x&z|!z&x&y",
"!(!x&y|!y&x|z)|!x&y&z|!y&x&z",
"!(x&y)&z|!z&x&y",
"!(!z&x|y)|!x&z|!z&x&y",
"!(x&z)&y|!y&x&z",
"!(!y&x|z)|!x&y|!y&x&z",
"!(x&y)&z|!z&y",
"!x|!y&z|!z&y",
"!(y&z)&x",
"!(!x&y|z)|!y&x",
"!y&z|!z&x",
"!y|!z&x",
"!y&x|!z&y",
"!y&x|!z",
"!y&(x|z)|!z&y",
"!y|!z",
"!(y&z)&x|!x&y&z",
"!(!x&y|z)|!x&y&z|!y&x",
"!(x&y)&z|!z&x",
"!x&z|!y|!z&x",
"!(x&z)&y|!y&x",
"!x&y|!y&x|!z",
"!x&y|!y&z|!z&x",
"!(x&y&z)",
"x&y&z",
"!(x|y|z)|x&y&z",
"!x&!y&z|x&y&z",
"!x&!y|x&y&z",
"!x&!z&y|x&y&z",
"!x&!z|x&y&z",
"!(!y&!z|x|y&z)|x&y&z",
"!(x|y&z)|x&y&z",
"y&z",
"!(x|y|z)|y&z",
"!x&z|y&z",
"!x&!y|y&z",
"!x&y|y&z",
"!x&!z|y&z",
"!x&(y|z)|y&z",
"!x|y&z",
"!y&!z&x|x&y&z",
"!y&!z|x&y&z",
"!(!x&!z|x&z|y)|x&y&z",
"!(x&z|y)|x&y&z",
"!(!x&!y|x&y|z)|x&y&z",
"!(x&y|z)|x&y&z",
"!(!x&!y|x&y|z)|!x&!y&z|x&y&z",
"!((x|y)&z|x&y)|x&y&z",
"!y&!z&x|y&z",
"!y&!z|y&z",
"!x&z|!y&!z&x|y&z",
"!(x&z|y)|y&z",
"!x&y|!y&!z&x|y&z",
"!(x&y|z)|y&z",
"!x&(y|z)|!y&!z&x|y&z",
"!x|!y&!z|y&z",
"x&z",
"!(x|y|z)|x&z",
"!y&z|x&z",
"!x&!y|x&z",
"!x&!z&y|x&z",
"!x&!z|x&z",
"!x&!z&y|!y&z|x&z",
"!(x|y&z)|x&z",
"(x|y)&z",
"!(x|y|z)|(x|y)&z",
"z",
"!x&!y|z",
"!x&y|x&z",
"!(!y&z|x)|x&z",
"!x&y|z",
"!x|z",
"!y&x|x&z",
"!y&!z|x&z",
"!y&(x|z)|x&z",
"!y|x&z",
"!x&!z&y|!y&x|x&z",
"!(x&y|z)|x&z",
"!x&!z&y|!y&(x|z)|x&z",
"!x&!z|!y|x&z",
"!y&x|y&z",
"!(!x&z|y)|y&z",
"!y&x|z",
"!y|z",
"!x&y|!y&x|x&z",
"!x&!z|!y&x|y&z",
"!x&y|!y&x|z",
"!x|!y|z",
"x&y",
"!(x|y|z)|x&y",
"!x&!y&z|x&y",
"!x&!y|x&y",
"!z&y|x&y",
"!x&!z|x&y",
"!x&!y&z|!z&y|x&y",
"!(x|y&z)|x&y",
"(x|z)&y",
"!(x|y|z)|(x|z)&y",
"!x&z|x&y",
"!(!z&y|x)|x&y",
"y",
"!x&!z|y",
"!x&z|y",
"!x|y",
"!z&x|x&y",
"!y&!z|x&y",
"!x&!y&z|!z&x|x&y",
"!(x&z|y)|x&y",
"!z&(x|y)|x&y",
"!z|x&y",
"!x&!y&z|!z&(x|y)|x&y",
"!x&!y|!z|x&y",
"!z&x|y&z",
"!(!x&y|z)|y&z",
"!x&z|!z&x|x&y",
"!x&!y|!z&x|y&z",
"!z&x|y",
"!z|y",
"!x&z|!z&x|y",
"!x|!z|y",
"(y|z)&x",
"!(x|y|z)|(y|z)&x",
"!y&z|x&y",
"!(!z&x|y)|x&y",
"!z&y|x&z",
"!(!y&x|z)|x&z",
"!y&z|!z&y|x&y",
"!x&!y|!z&y|x&z",
"(x|y)&z|x&y",
"!(x|y|z)|(x|y)&z|x&y",
"x&y|z",
"!x&!y|x&y|z",
"x&z|y",
"!x&!z|x&z|y",
"y|z",
"!x|y|z",
"x",
"!y&!z|x",
"!y&z|x",
"!y|x",
"!z&y|x",
"!z|x",
"!y&z|!z&y|x",
"!y|!z|x",
"x|y&z",
"!y&!z|x|y&z",
"x|z",
"!y|x|z",
"x|y",
"!z|x|y",
"x|y|z",
"!x|x",
};

void precalc() {
    ofstream fout("good.cpp");
    string bad;
    bad += (char) 126;
    for (int len = 0; len <= LMAX; ++len) {
        for (int i = 0; i < (1 << 8); ++i) {
            dp1[len][i] = bad;
            dp2[len][i] = bad;
            dp3[len][i] = bad;
        }
    }
    dp1[1][(1 << 8) - (1 << 4)] = "x";
    dp1[1][(1 << 2) | (1 << 3) | (1 << 6) | (1 << 7)] = "y";
    dp1[1][(1 << 1) | (1 << 3) | (1 << 5) | (1 << 7)] = "z";
    int full = (1 << 8) - 1;
    for (int len1 = 1; len1 <= LMAX; ++len1) {
        for (int conf1 = 0; conf1 < (1 << 8); ++conf1) {
            if (dp2[len1][conf1] != bad && 
                    len1 + 2 <= LMAX && ("(" + dp2[len1][conf1] + ")") < dp1[len1 + 2][conf1]) {
                dp1[len1 + 2][conf1] = "(" + dp2[len1][conf1] + ")";
            }
            if (dp3[len1][conf1] != bad && 
                    len1 + 2 <= LMAX && ("(" + dp3[len1][conf1] + ")") < dp1[len1 + 2][conf1]) {
                dp1[len1 + 2][conf1] = "(" + dp3[len1][conf1] + ")";
            }
            if (dp1[len1][conf1] != bad && 
                    len1 + 2 <= LMAX && ("(" + dp1[len1][conf1] + ")") < dp1[len1 + 2][conf1]) {
                dp1[len1 + 2][conf1] = "(" + dp1[len1][conf1] + ")";
            }
            if (dp1[len1][conf1] != bad &&
                    len1 + 1 <= LMAX && ("!" + dp1[len1][conf1]) < dp1[len1 + 1][full ^ conf1]) {
                dp1[len1 + 1][full ^ conf1] = "!" + dp1[len1][conf1];
            }

            for (int len2 = 1; len2 <= len1; ++len2) {
                for (int conf2 = 0; conf2 < (1 << 8); ++conf2) {
                    string s, v1, v2;
                    v1 = min({dp1[len1][conf1], dp3[len1][conf1]});
                    v2 = min({dp1[len2][conf2], dp3[len2][conf2]});
                    s = v1 + "&" + v2;
                    if (v1 != bad && v2 != bad) {
                        if (len1 + len2 + 1 <= LMAX && dp3[len1 + len2 + 1][conf1 & conf2] > s) {
                            dp3[len1 + len2 + 1][conf1 & conf2] = s;
                        }
                    }
                    v1 = min({dp1[len1][conf1], dp2[len1][conf1], dp3[len1][conf1]});
                    v2 = min({dp1[len2][conf2], dp2[len2][conf2], dp3[len2][conf2]});
                    s = v1 + "|" + v2;
                    if (v1 != bad && v2 != bad) {
                        if (len1 + len2 + 1 <= LMAX && dp2[len1 + len2 + 1][conf1 | conf2] > s) {
                            dp2[len1 + len2 + 1][conf1 | conf2] = s;
                        }
                    }
                    v1 = min({dp1[len1][conf1], dp3[len1][conf1]});
                    v2 = min({dp1[len2][conf2], dp3[len2][conf2]});
                    s = v2 + "&" + v1;
                    if (v1 != bad && v2 != bad) {
                        if (len1 + len2 + 1 <= LMAX && dp3[len1 + len2 + 1][conf1 & conf2] > s) {
                            dp3[len1 + len2 + 1][conf1 & conf2] = s;
                        }
                    }
                    v1 = min({dp1[len1][conf1], dp2[len1][conf1], dp3[len1][conf1]});
                    v2 = min({dp1[len2][conf2], dp2[len2][conf2], dp3[len2][conf2]});
                    s = v2 + "|" + v1;
                    if (v1 != bad && v2 != bad) {
                        if (len1 + len2 + 1 <= LMAX && dp2[len1 + len2 + 1][conf1 | conf2] > s) {
                            dp2[len1 + len2 + 1][conf1 | conf2] = s;
                        }
                    }
                }
            }
        }
    }
    for (int conf = 0; conf < (1 << 8); ++conf) {
        sol[conf] = bad;
        for (int len = 1; len <= LMAX && sol[conf] == bad; ++len) {
            if (dp1[len][conf] < sol[conf]) {
                sol[conf] = dp1[len][conf];
            }
            if (dp2[len][conf] < sol[conf]) {
                sol[conf] = dp2[len][conf];
            }
            if (dp3[len][conf] < sol[conf]) {
                sol[conf] = dp3[len][conf];
            }
        }
        fout << "\"" << sol[conf] << "\"," << '\n';
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    // precalc();
    int t;
    cin >> t;
    while (t-- > 0) {
        string s;
        cin >> s;
        int conf = 0;
        for (int i = 0; i < 8; ++i) {
            conf |= (s[i] - '0') << i;
        }
        cout << good[conf] << '\n';
    }
}