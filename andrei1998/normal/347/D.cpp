#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100 + 5;
const int SIGMA = 256;

int N, M, K;
string a, b, str;

int trans[NMAX][SIGMA];

int pi[NMAX];
void precomp() {
    int k = 0;
    for (int i = 2; i <= K; ++i) {
        while (k && str[i] != str[k + 1])
            k = pi[k];
        if (str[i] == str[k + 1])
            ++k;
        pi[i] = k;
    }
    for (int i = 0; i < K; ++i) {
        for (int ch = 0; ch < SIGMA; ++ch) {
            int k = i;
            while (k && ch != str[k + 1])
                k = pi[k];
            if (ch == str[k + 1]) {
                ++k;
            }
            trans[i][ch] = k;
        }
    }
}

// Generic update function for dp with father
template <typename Ftype>
void upd_dp(int &dp, Ftype &father,
            const int val, const Ftype ft) {
    if (val >= dp) {
        dp = val;
        father = ft;
    }
}

int dp[NMAX][NMAX][NMAX]; // dp[i][j][k] = start with (i, j, k), how
                          //               much could you extend
tuple <int, int, int, bool> father[NMAX][NMAX][NMAX];

int main() {
    cin >> a >> b >> str;

    N = a.size(), M = b.size(), K = str.size();
    a = " " + a;
    b = " " + b;
    str = " " + str;

    precomp();

    for (int i = N; i; --i) {
        for (int j = M; j; --j) {
            // check order
            for (int k = 0; k < K; ++k) {
                auto upd = [&](const int val, const tuple <int, int, int, bool> ft) {
                    upd_dp(dp[i][j][k], father[i][j][k], val, ft);
                };

                upd(dp[i + 1][j][k], make_tuple(i + 1, j, k, false));
                upd(dp[i][j + 1][k], make_tuple(i, j + 1, k, false));
                if (a[i] == b[j] && trans[k][a[i]] != K)
                    upd(1 + dp[i + 1][j + 1][trans[k][a[i]]],
                        make_tuple(i + 1, j + 1, trans[k][a[i]], true));
            }
        }
    }

    if (dp[1][1][0] == 0) {
        cout << "0\n";
        return 0;
    }

    int i = 1, j = 1, k = 0;
    string sol;
    while (i <= N && j <= M) {
        bool taken;
        tie(i, j, k, taken) = father[i][j][k];
        if (taken)
            sol += a[i - 1];
    }
    cout << sol << endl;
    return 0;
}