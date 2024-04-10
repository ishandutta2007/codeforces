#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 405;

vector<int> G[NMAX];
int dist[NMAX][NMAX];
vector<int> atDist[NMAX][NMAX];

int candidates[NMAX];
double probs[NMAX];
double maxp[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
        dist[x][y] = dist[y][x] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            atDist[i][dist[i][j]].push_back(j);
        }
    }

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        double pr1 = 0;
        for (int d = 0; d < n; ++d) {
            if (atDist[i][d].empty()) continue;
            memset(probs, 0, sizeof probs);
            double pr2 = 1.0 / SZ(atDist[i][d]);
            for (int n1: atDist[i][d]) {
                double add = 1.0 / SZ(G[n1]) / SZ(atDist[i][d]);
                for (int n2: G[n1]) {
                    probs[n2] += add;
                }
            }
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (probs[j] > 0) {
                    candidates[cnt++] = j;
                }
            }
            
            for (int j = 0; j < n; ++j) {
                double pr3 = 0;
                for (int n1 = 0; n1 < cnt; ++n1) {
                    int x = dist[j][candidates[n1]];
                    maxp[x] = max(maxp[x], probs[candidates[n1]]);
                }
                for (int n1 = 0; n1 < cnt; ++n1) {
                    int x = dist[j][candidates[n1]];
                    pr3 += maxp[x];
                    maxp[x] = 0;
                }
                pr2 = max(pr2, pr3);
            }

            pr1 += (double) SZ(atDist[i][d]) / n * pr2;
        }
        ans = max(ans, pr1);
    }

    cout << setprecision(14) << fixed;
    cout << ans << '\n';
}