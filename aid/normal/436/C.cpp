#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 11, MAXK = 1005, INF = 1000 * 1000 * 1000 + 5;
int d[MAXK], p[MAXK], n, m;
char t[MAXK][MAXN][MAXN], used[MAXK];
vector< pair<int, int> > g[MAXK], a;

int dif(int p, int q) {
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(t[p][i][j] != t[q][i][j])
                res++;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int k, w;
    cin >> n >> m >> k >> w;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            for(int l = 0; l < m; l++)
                cin >> t[i][j][l];
    for(int i = 0; i < k; i++)
        for(int j = i + 1; j < k; j++) {
            int d = w * dif(i, j);
            g[i].push_back(make_pair(j, d));
            g[j].push_back(make_pair(i, d));
        }
    for(int i = 0; i < k; i++) {
        d[i] = n * m;
        p[i] = -1;
    }
    for(int i = 0; i < k; i++) {
        int minv = -1;
        for(int j = 0; j < k; j++)
            if(!used[j] && (minv == -1 || d[j] < d[minv]))
                minv = j;
        used[minv] = true;
        a.push_back(make_pair(minv, p[minv]));
        for(size_t i = 0; i < g[minv].size(); i++)
            if(!used[g[minv][i].first] &&
               g[minv][i].second < d[g[minv][i].first]) {
                d[g[minv][i].first] = g[minv][i].second;
                p[g[minv][i].first] = minv;
            }
    }
    int ans = 0;
    for(int i = 0; i < k; i++)
        ans += d[i];
    cout << ans << '\n';
    for(size_t i = 0; i < a.size(); i++)
        cout << a[i].first + 1 << ' ' << a[i].second + 1 << '\n';
    return 0;
}