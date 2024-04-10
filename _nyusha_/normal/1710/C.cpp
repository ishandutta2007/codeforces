#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const maxn = 2e5 + 5;
ll mod = 998244353;
ll dp[maxn][2][2][2][2][2][3];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = 0;
    for (auto c : s) n = (n * 2 + c - '0') % mod;
    int ans = (n + 1) * (n + 1) % mod * (n + 1) % mod;
    s = "#" + s;
    dp[0][0][0][0][0][0][0] = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        for (int la = 0; la < 2; la++) {
            for (int lb = 0; lb < 2; lb++) {
                for (int lc = 0; lc < 2; lc++) {
                    for (int f1 = 0; f1 < 2; f1++) {
                        for (int f2 = 0; f2 < 2; f2++) {
                            for (int win = 0; win <= 2; win++) {
                                for (int a = 0; a < 2; a++) {
                                    for (int b = 0; b < 2; b++) {
                                        for (int c = 0; c < 2; c++) {
                                            if ((a > s[i] - '0' && !la) || (b > s[i] - '0' && !lb) || (c > s[i] - '0' && !lc)) continue;
                                            if ((!f1 && (a^b) > (a^c)) || (!f2 && (a^c) > (b^c))) continue;
                                            int nxt = min(2 * win - (b^c) + (a^b) + (a^c), 2);
                                            if (nxt < 0) continue;
                                            dp[i][(la|(a < s[i] - '0'))][(lb|(b < s[i] - '0'))][(lc|(c < s[i] - '0'))][(f1|((a^b) < (a^c)))][(f2|((a^c) < (b^c)))][nxt] += dp[i - 1][la][lb][lc][f1][f2][win];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    for (int f1 = 0; f1 < 2; f1++) {
                        for (int f2 = 0; f2 < 2; f2++) {
                            for (int win = 0; win <= 2; win++) {
                                dp[i][a][b][c][f1][f2][win] %= mod;
                            }
                        }
                    }
                }
            }
        }
    }
    ll add = 0;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int f1 = 1; f1 < 2; f1++) {
                    for (int f2 = 1; f2 < 2; f2++) {
                        for (int win = 1; win <= 2; win++) {
                            add += dp[s.size() - 1][a][b][c][f1][f2][win];
                        }
                    }
                }
            }
        }
    }
    cout << add % mod * 6 % mod << '\n';
    return 0;
}