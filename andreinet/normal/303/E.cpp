#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
#define WRITE(x) (cerr << #x << ": " << x << endl)
using namespace std;

const int NMAX = 83;

int L[NMAX], R[NMAX];
double p1[NMAX], p2[NMAX], p3[NMAX];
double ans[NMAX][NMAX];

int n;

void add(double dp[NMAX][NMAX], int e) {
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            dp[i + 1][j] += dp[i][j] * p1[e];
            dp[i][j + 1] += dp[i][j] * p2[e];
            dp[i][j] *= p3[e];
        }
    }
}

void add(double dp[NMAX][NMAX], int left, int right) {
    for (int i = left; i < right; ++i) {
        add(dp, i);
    }
}

void solve(double dp[NMAX][NMAX], int left, int right) {
    if (left + 1 == right) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; i + j < n; ++j) {
                double cp = dp[i][j] * p2[left] / (j + 1);
                ans[left][i + 1] += cp;
                ans[left][i + j + 2] -= cp;
            }
        }
    } else {
        int mid = (left + right) / 2;
        double ndp[NMAX][NMAX];
        memcpy(ndp, dp, sizeof ndp);
        add(ndp, left, mid);
        solve(ndp, mid, right);
        add(dp, mid, right);
        solve(dp, left, mid);
    }
    //
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    cin >> n;

    vector<int> X;
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
        X.push_back(L[i]);
        X.push_back(R[i]);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    cout << setprecision(17) << fixed;

    for (int j = 0; j < SZ(X) - 1; ++j) {
        int l = X[j], r = X[j + 1];
        for (int i = 0; i < n; ++i) {
            p1[i] = p2[i] = 0;
            if (R[i] <= l) {
                p1[i] = 1;
            } else if (L[i] < l) {
                p1[i] = (double) (l - L[i]) / (R[i] - L[i]);
            }
            if (L[i] <= l && r <= R[i]) {
                p2[i] = (double) (r - l) / (R[i] - L[i]);
            }
            p3[i] = 1 - p1[i] - p2[i];
        }
        double dp[NMAX][NMAX] = {0};
        dp[0][0] = 1;
        solve(dp, 0, n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans[i][j] += ans[i][j - 1];
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}