#include <bits/stdc++.h>
using namespace std;

#define bit(x, y) ((x >> y) & 1)
const int MOD = 504;
const int ST = 48;

long long dp[20][2][ST][MOD][2];
int val_to_st[2521];
int st_to_val[50];
pair<int, int> transition[48][504][10];

void gogo(int pos, int ok, int st, int r, int end5, long long val, const vector<int> &digits) {
    int nxt_pos = pos - 1;
    int nxt_d = digits[nxt_pos];
    for (int d = 0; d < 10; d++) {
        if (ok && d > nxt_d) continue;
        auto nxt_st_r = transition[st][r][d];
        int nxt_st = nxt_st_r.first;
        int nxt_r = nxt_st_r.second;
        bool nxt_ok = (ok && d == nxt_d);
        bool nxt_end5 = (d == 5 || d == 0);
        dp[nxt_pos][nxt_ok][nxt_st][nxt_r][nxt_end5] += val;
    }
}

long long calc(long long x) {
    memset(dp, 0, sizeof dp);
    vector<int> digits(19);
    for (int i = 0; i < 19; i++) {
        digits[i] = x % 10;
        x /= 10;
    }
    dp[19][1][0][0][1] = 1;
    for (int pos = 19; pos > 0; pos--) {
        for (int ok = 0; ok < 2; ok++) {
            for (int st = 0; st < ST; st++) {
                for (int r = 0; r < MOD; r++) {
                    for (int end5 = 0; end5 < 2; end5++) {
                        long long val = dp[pos][ok][st][r][end5];
                        if (val) {
                            gogo(pos, ok, st, r, end5, val, digits);
                        }
                    }
                }
            }
        }
    }

    long long res = 0;

    for (int ok = 0; ok < 2; ok++) {
        for (int st = 0; st < ST; st++) {
            for (int r = 0; r < MOD; r++) {
                for (int end5 = 0; end5 < 2; end5++) {
                    int val = st_to_val[st];
                    if (val % 5 == 0 && end5 == 0) continue;
                    if (val % 5 == 0) val /= 5;
                    if (r % val == 0) {
                        res += dp[0][ok][st][r][end5];
                    }
                }
            }
        }
    }

    return res;
}

int main() {
    { // compress lcms of digits
        set<int> all_val;
        for (int i = 0; i < (1 << 9); i++) {
            int tmp = 1;
            for (int j = 0; j < 9; j++) {
                if (bit(i, j)) {
                    tmp = tmp * (j + 1) / __gcd(tmp, j + 1);
                }
            }
            all_val.insert(tmp);
        }
        int cur = 0;
        for (int e : all_val) {
            val_to_st[e] = cur;
            st_to_val[cur] = e;
            cur++;
        }
    }
    { // precompute the transition
        for (int i = 0; i < ST; i++) {
            for (int j = 0; j < 504; j++) {
                for (int d = 0; d < 10; d++) {
                    int val = st_to_val[i];
                    int nxt_val = val;
                    if (d != 0) {
                        nxt_val = val * d / __gcd(d, val);
                    }
                    int nxt_j = (j * 10 + d) % MOD;
                    transition[i][j][d] = make_pair(val_to_st[nxt_val], nxt_j);
                }
            }
        }
    }

    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }
}