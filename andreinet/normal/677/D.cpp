#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 305, CMAX = NMAX * NMAX, INF = 0x3f3f3f3f;

int A[NMAX][NMAX];
vector<pair<int, int>> allv[CMAX];

int dist[NMAX][NMAX];
int inds[NMAX], dcol[NMAX];
int lastUpdate[NMAX];

inline int mabs(int x) {
    return x < 0 ? -x: x;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
            allv[A[i][j]].push_back(make_pair(i, j));
        }
    }
    allv[0].push_back(make_pair(1, 1));
    for (int i = 1; i <= n * m; ++i) {
        sort(allv[i].begin(), allv[i].end());
    }

    for (int c = 1; c <= p; ++c) {
        memset(inds, 0, sizeof inds);
        memset(dcol, INF, sizeof dcol);
        memset(lastUpdate, 0, sizeof lastUpdate);
        int ind = 0;
        for (int i = 1; i <= n; ++i) {
            for (const pair<int, int>& p: allv[c - 1]) {
                int xdist = c == 1 ? 0: dist[p.first][p.second];
                if (lastUpdate[p.second] != i) {
                    inds[p.second] = p.first;
                    dcol[p.second] = xdist + mabs(p.first - i);
                    lastUpdate[p.second] = i;
                } else {
                    int d = xdist + mabs(p.first - i);
                    if (d < dcol[p.second]) {
                        dcol[p.second] = d;
                        inds[p.second] = p.first;
                    }
                }
            }
            for (; ind < SZ(allv[c]) && allv[c][ind].first == i; ++ind) {
                int j = allv[c][ind].second;
                dist[i][j] = INF;
                for (int j1 = 1; j1 <= m; ++j1) {
                    if (inds[j1] == 0) continue;
                    dist[i][j] = min(dist[i][j], dcol[j1] + mabs(j1 - j));
                }
            }
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i][j] == p) {
                ans = dist[i][j];
            }
        }
    }
    cout << ans << '\n';
}