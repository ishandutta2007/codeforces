#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 405;
const double EPS = 1e-9;
int d[MAXN][MAXN];
double pr[MAXN];
vector<int> g[MAXN], v[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = (i == j? 0 : MAXN);
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
        d[v][u] = 1;
        d[u][v] = 1;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    double ans = 0;
    for(int s = 0; s < n; s++) {
        int maxd = 0;
        for(int i = 0; i < n; i++) {
            v[d[s][i]].push_back(i);
            maxd = max(maxd, d[s][i]);
        }
        double cur = 0;
        for(int dd = 0; dd <= maxd; dd++) {
            for(size_t i = 0; i < v[dd].size(); i++) {
                int vv = v[dd][i];
                for(size_t j = 0; j < g[vv].size(); j++)
                    pr[g[vv][j]] += 1. / g[vv].size();
            }
            vector< pair<int, double> > u;
            for(int i = 0; i < n; i++) {
                if(pr[i] > EPS)
                    u.push_back(make_pair(i, pr[i]));
                pr[i] = 0;
            }
            double x = 1;
            for(int t = 0; t < n; t++) {
                for(size_t i = 0; i < u.size(); i++)
                    if(u[i].second > pr[d[t][u[i].first]])
                        pr[d[t][u[i].first]] = u[i].second;
                double y = 0;
                for(size_t i = 0; i < u.size(); i++) {
                    y += pr[d[t][u[i].first]];
                    pr[d[t][u[i].first]] = 0;
                }
                x = max(x, y);
            }
            cur += x / n;
        }
        for(int i = 0; i <= maxd; i++)
            v[i].clear();
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}