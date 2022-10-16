#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 505, MAXT = 105;
double a[MAXN][2 * MAXN], d[MAXT][MAXT], d0[MAXT][MAXT], pr[MAXT], pr0[MAXT];
int id[MAXN], p[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n, m, k;
    cin >> n >> m >> k;
    int t = 0;
    for(int i = 0; i < n; i++) {
        int trap;
        cin >> trap;
        if(trap) {
            id[i] = t;
            p[t] = i;
            t++;
        }
        else
            id[i] = -1;
    }
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++) {
        a[i][i] = 1;
        a[i][n + i] = 1;
        if(id[i] != -1)
            continue;
        for(size_t j = 0; j < g[i].size(); j++)
            a[i][g[i][j]] -= (double)1 / g[g[i][j]].size();
    }
    for(int i = 0; i < n; i++) {
        int maxrow = i;
        for(int j = i + 1; j < n; j++)
            if(fabs(a[maxrow][i]) < fabs(a[j][i]))
                maxrow = j;
        for(int j = 0; j < 2 * n; j++)
            swap(a[i][j], a[maxrow][j]);
        double tmp = a[i][i];
        for(int j = 0; j < 2 * n; j++)
            a[i][j] /= tmp;
        for(int j = i + 1; j < n; j++) {
            tmp = a[j][i];
            for(int l = 0; l < 2 * n; l++)
                a[j][l] -= a[i][l] * tmp;
        }
    }
    for(int i = n - 1; i >= 0; i--)
        for(int j = i - 1; j >= 0; j--) {
            double tmp = a[j][i];
            a[j][i] = 0;
            for(int l = n; l < 2 * n; l++)
                a[j][l] -= a[i][l] * tmp;
        }
    for(int i = 0; i < t; i++)
        for(int j = 0; j < t; j++)
            for(size_t l = 0; l < g[p[j]].size(); l++)
                d[i][j] += a[g[p[j]][l]][n + p[i]] / g[g[p[j]][l]].size();
    for(int i = 0; i < t; i++)
        for(size_t j = 0; j < g[p[i]].size(); j++)
            pr[i] += a[g[p[i]][j]][n] / g[g[p[i]][j]].size();
    k -= 2;
    while(k) {
        if(k & 1) {
            for(int i = 0; i < t; i++) {
                pr0[i] = 0;
                for(int j = 0; j < t; j++)
                    pr0[i] += pr[j] * d[j][i];
            }
            swap(pr, pr0);
        }
        k >>= 1;
        for(int i = 0; i < t; i++)
            for(int j = 0; j < t; j++) {
                d0[i][j] = 0;
                for(int l = 0; l < t; l++)
                    d0[i][j] += d[i][l] * d[l][j];
            }
        swap(d, d0);
    }
    cout << pr[t - 1] << '\n';
    return 0;
}