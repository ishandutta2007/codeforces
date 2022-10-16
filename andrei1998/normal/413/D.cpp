#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2000 + 5;

int N, K;
int v[NMAX];

int update_mask(int mask, int nr) {
    if (nr == 2 && mask & 1)
        mask = 0;
    return mask + nr;
}

const int MOD = 1000000000 + 7;
const int KMAX = 10;

int dp[NMAX][1 << KMAX];

inline void upd_dp(int &where, const int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

inline void subtr(int &where, const int val) {
    where -= val;
    if (where < 0)
        where += MOD;
}

int main() {
    cin >> N >> K;
    --K;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        v[i] /= 2;
    }

    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (1 << K); ++j) {
            if (!dp[i][j])
                continue;
            vector <int> vals;
            if (v[i + 1] == 0)
                vals = {1, 2};
            else
                vals = {v[i + 1]};
            for (auto val: vals) {
                const int n_mask = update_mask(j, val);
                if (n_mask < (1 << K))
                    upd_dp(dp[i + 1][n_mask], dp[i][j]);
            }
        }
    }

    int all = 1;
    for (int i = 1; i <= N; ++i)
        if (v[i] == 0)
            all = (2LL * all) % MOD;
    for (int j = 0; j < (1 << K); ++j)
        subtr(all, dp[N][j]);
    cout << all << endl;
    return 0;
}