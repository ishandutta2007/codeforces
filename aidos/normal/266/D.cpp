#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e2 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, m;
int a[maxn * maxn], b[maxn * maxn], w[maxn * maxn];
int dp[maxn][maxn];
pair <double, int> c[maxn];
vector<int> g[maxn * maxn];

vector<int> A[maxn * maxn];
vector<int> B[maxn * maxn];
double calc(int id) {
    int u = a[id];
    int v = b[id];
    int W = w[id];
    for(int i = 1; i <= n; i++) {
        if(dp[u][i] >= dp[v][i] + W) {
            c[i] = make_pair(0, i);
        }else if(dp[v][i] >= dp[u][i] + W) {
            c[i] = make_pair(W, i);
        } else {
            double mid = (W+dp[v][i] - dp[u][i])/2;
            c[i] = make_pair(mid, i);
        }
    }
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) {
        g[id].push_back(c[i].second);
        A[id].push_back(dp[v][c[i].second]);
        B[id].push_back(dp[u][c[i].second]);
    }
    for(int i = n-2; i >= 0; i--) {
        B[id][i] = max(B[id][i], B[id][i+1]);
    }
    for(int i = 1; i < n; i++) {
        A[id][i] = max(A[id][i], A[id][i-1]);
    }
    double cur = inf;
    for(int i = 1; i < n; i++) {
        double x = (A[id][i-1] + B[id][i] + w[id])/2.0;
        if(x < A[id][i-1]) x = A[id][i-1];
        if(x < B[id][i]) x = B[id][i];
        cur = min(cur, x);
    }
    return cur;
};
bool can(double x) {
    for(int i = 0; i < m; i++) {
        int u = a[i], v = b[i];
        for(int j = 1; j < n; j++) {
            if(x < A[i][j-1] || x < B[i][j]) continue;
            if(x - A[i][j-1] + x-B[i][j] >= w[i]) return 1;
        }
    }
    return 0;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = inf;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> w[i];
        dp[a[i]][b[i]] = min(dp[a[i]][b[i]], w[i]);
        dp[b[i]][a[i]] = min(dp[b[i]][a[i]], w[i]);
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    double ans = inf;
    for(int i = 0; i < m; i++) {
        ans = min(ans, calc(i));
    }
    printf("%.12lf\n", ans);
}

int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}