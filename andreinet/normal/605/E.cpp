#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 1005;
const double EPS = 1e-10;

double P[NMAX][NMAX];
double dist[NMAX], sum[NMAX], prob[NMAX];
bool used[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            P[i][j] = (double) x / 100;
        }
    }

    for (int i = 1; i <= n; ++i) {
        dist[i] = 1e99;
        prob[i] = 1;
        sum[i] = 0;
    }

    dist[n] = 0;
    for (int i = 1; i <= n; ++i) {
        int node = -1;
        for (int j = 1; j <= n; ++j) {
            if (!used[j] && (node == -1 || dist[j] < dist[node])) {
                node = j;
            }
        }
        if (node == 1) break;
        used[node] = true;
        for (int j = 1; j <= n; ++j) {
            if (!used[j]) {
                sum[j] += dist[node] * prob[j] * P[j][node];
                prob[j] *= (1 - P[j][node]);
                if (prob[j] + EPS < 1) {
                    dist[j] = (1 + sum[j]) / (1 - prob[j]);
                }
            }
        }
    }

    cout << setprecision(17) << fixed;
    cout << dist[1] << '\n';
}