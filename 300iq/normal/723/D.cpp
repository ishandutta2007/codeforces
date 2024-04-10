#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, k;
vector <pair <int, int> > v;
char c[100][100];
char g[100][100];

bool good(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && c[i][j] == '.');
}

bool dfs(int i, int j) {
    v.pb({i, j});
    c[i][j] = '*';
    bool bad = (i == 0 || i == n - 1 || j == 0 || j == m - 1);
    for (int t = 0; t < 4; t++) {
        if (good(i + dx[t], j + dy[t])) {
            bad |= dfs(i + dx[t], j + dy[t]);
        }
    }
    return bad;
}

bool cmp(const vector <pair <int, int> > &a, const vector <pair <int, int> > &b) {
    return a.size() < b.size();
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &c[i][j]);
            g[i][j] = c[i][j];
        }
    }
    vector <vector <pair <int, int> > > d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                v.clear();
                bool t = dfs(i, j);
                if (t) {
                    continue;
                } else {
                    d.pb(v);
                }
            }
        }
    }
    sort(all(d), cmp);
    int need = (int) d.size() - k;
    int res = 0;
    for (int i = 0; i < need; i++) {
        for (auto f : d[i]) {
            g[f.fc][f.sc] = '*'; 
            res++;
        }
    }
    printf("%d\n", res);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", g[i][j]);
        }
        puts("");
    }
}