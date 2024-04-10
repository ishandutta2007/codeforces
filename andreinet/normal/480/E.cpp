#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 2005;

char A[NMAX][NMAX];
int up[NMAX][NMAX];
int down[NMAX][NMAX];
int dp[NMAX][NMAX];

int build(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            (A[i][j] == '.' && (up[i][j] = 1 + up[i - 1][j]));
        }
    }
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= m; ++j) {
            (A[i][j] == '.' && (down[i][j] = 1 + down[i + 1][j]));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i][j] == '.') {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

bool can(int n, int m, int row, int len) {
    deque<int> deqUp, deqDown;
    for (int j = 1; j <= m; ++j) {
        while (!deqUp.empty() && deqUp.front() <= j - len) {
            deqUp.pop_front();
        }
        while (!deqDown.empty() && deqDown.front() <= j - len) {
            deqDown.pop_front();
        }
        while (!deqUp.empty() && up[row][j] <= up[row][deqUp.back()]) {
            deqUp.pop_back();
        }
        deqUp.push_back(j);
        while (!deqDown.empty() && down[row][j] <= down[row][deqDown.back()]) {
            deqDown.pop_back();
        }
        deqDown.push_back(j);

        if (j >= len && up[row][deqUp.front()] + down[row][deqDown.front()] - 1 >= len) {
            return true;
        }
    }
    return false;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> (A[i] + 1);
    }

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        queries.push_back(make_pair(x, y));
        A[x][y] = 'X';
    }
    
    int ans = build(n, m);
    vector<int> fans(q);
    for (int i = q - 1; i >= 0; --i) {
        int x = queries[i].first, y = queries[i].second;

        A[x][y] = '.';
        for (int i = x; i > 0 && A[i][y] != 'X'; --i) {
            down[i][y] = 1 + down[i + 1][y];
        }
        for (int i = x; i <= n && A[i][y] != 'X'; ++i) {
            up[i][y] = 1 + up[i - 1][y];
        }
        
        fans[i] = ans;
        while (can(n, m, x, ans + 1)) {
            ans++;
        }
    }
    for (int p: fans) {
        cout << p << '\n';
    }
}