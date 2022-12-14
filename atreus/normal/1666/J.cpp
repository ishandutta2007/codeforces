#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 200 + 10;
const ll inf = 1e18;

int n;
ll dp[maxn][maxn], c[maxn][maxn], par[maxn][maxn];
int baba[maxn][maxn];
int p[maxn];

ll Sum(int x1, int y1, int x2, int y2) {
    return par[x2][y2] - par[x1 - 1][y2] - par[x2][y1 - 1] + par[x1 - 1][y1 - 1];
}

ll Cost(int l, int r) {
    return Sum(1, l, n, r) - Sum(l, l, r, r);
}

void find_tree(int l, int r, int dad = 0) {
    if (l > r)
        return;
    if (l == r) {
        p[l] = dad;
        return;
    }
    int m = baba[l][r];
    p[m] = dad;
    find_tree(l, m - 1, m);
    find_tree(m + 1, r, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            par[i][j] = par[i - 1][j] + par[i][j - 1] - par[i - 1][j - 1] + c[i][j];
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = inf;
            for (int m = l; m <= r; m++) {
                ll tmp = dp[l][r];
                dp[l][r] = min(dp[l][r], dp[l][m - 1] + dp[m + 1][r] + Cost(l, m - 1) + Cost(m + 1, r));
                if (dp[l][r] < tmp)
                    baba[l][r] = m;
            }
        }
    }
    find_tree(1, n);
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
}