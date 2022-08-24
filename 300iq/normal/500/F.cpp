#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = 4000 + 7, MAXM = (int) 2e4 + 7;
int n, m, p;
int dp[MAXN], sufdp[MAXN][MAXN], left[MAXN], ans[MAXM];
vector <pair <int, int> > w[MAXM];
vector <pair <int, int> > q[MAXM];

void solve(int t) {
    int s = max(1, t - p), e = min(t + p - 1, MAXM - 6);
    vector <int> cur;
    cur.pb(-1);
    memset(dp, 0, sizeof dp);
    for (int i = t - 1; i >= s; i--) {
        for (int j = 0; j < (int) w[i].size(); j++) {
            cur.pb(i);
            int ind = (int) cur.size() - 1;
            for (int p = 1; p < MAXN; p++) {
                sufdp[ind][p] = max(sufdp[ind][p - 1], sufdp[ind - 1][p]);
                if (p - w[i][j].fc >= 0) {
                    sufdp[ind][p] = max(sufdp[ind][p], sufdp[ind - 1][p - w[i][j].fc] + w[i][j].sc);
                }
            }
        }
    }
    int last = (int) cur.size() - 1;
    for (int i = t; i <= e; i++) {
        for (int j = 0; j < (int) w[i].size(); j++) {
            for (int p = MAXN - 1; p - w[i][j].fc >= 0; p--) {
                dp[p] = max(dp[p], dp[p - w[i][j].fc] + w[i][j].sc);
            }
        }
        while (last > 0 && i - p >= cur[last]) {
            last--;
        }
        for (int j = 0; j < (int) q[i].size(); j++) {
            for (int p = 0; p <= q[i][j].fc; p++) {
                ans[q[i][j].sc] = max(ans[q[i][j].sc], sufdp[last][p] + dp[q[i][j].fc - p]);
            }
        }
    }
}


int main() {
    int x, y, z;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        w[z].pb({x, y});
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        q[x].pb({y, i});
    }
    for (int i = 1; i <= MAXM - 6; i += p) {
        solve(i);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
}