#include <bits/stdc++.h>

using namespace std;

const int MAXN = 11;

int dp[MAXN][MAXN];
int n;
int ans;

void bad() {
    return;
}

void rec_i(int i);
void rec_j(int i, int j);
void rec_k(int i, int j, int k);

void rec_i(int i) {
    rec_j(i, 1);
    (i + 1 <= n ? rec_i(i + 1) : bad());
}

void rec_j(int i, int j) {
    rec_k(i, j, 1);
    (j + 1 <= n ? rec_j(i, j + 1) : bad());
}

void rec_k(int i, int j, int k) {
    dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
    (k + 1 <= n ? rec_k(i, j, k + 1) : bad());
}

void re_j(int i, int j) {
    cin >> dp[i][j];
    (j + 1 <= n ? re_j(i, j + 1) : bad());
}

void re_i(int i) {
    re_j(i, 1);
    (i + 1 <= n ? re_i(i + 1) : bad());
}

void rc_j(int i, int j) {
    ans = max(ans, dp[i][j]);
    (j + 1 <= n ? rc_j(i, j + 1) : bad());
}

void rc_i(int i) {
    rc_j(i, 1);
    (i + 1 <= n ? rc_i(i + 1) : bad());
}


int main() {
    cin >> n;
    re_i(1);
    rec_i(1);
    rc_i(1);
    cout << ans << endl;
}