#include<bits/stdc++.h>

using namespace std;

struct pt {
    int x, y, c;
};

int const maxn = 305, maxc = 2e6 + 5;
int Add[maxc], R[maxc], f[maxc];
pt b[maxc];
int cmp[maxn * maxn], sz[maxn * maxn], n, m;
int a[maxn][maxn];
vector < pair < int, int > > T = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector < pair < int, int > > good[maxc];
vector < int > bad[maxc];
int oks[maxn][maxn];

inline int gett(pair < int, int > cur) {
    return (cur.first - 1) * m + cur.second;
}

int get(int i) {
    if (i == cmp[i]) return i;
    return get(cmp[i]);
}

int add(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) return 1;
    if (sz[u] < sz[v]) {
        cmp[u] = v;
    }
    else if (sz[v] < sz[u]) cmp[v] = u;
    else {
        sz[u]++;
        cmp[v] = u;
    }
    return 0;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> m >> q;
    f[0] = 1;
    for (int i = 1; i <= q; ++i) cin >> b[i].x >> b[i].y >> b[i].c;
    for (int i = 0; i <= n * m; ++i) cmp[i] = i;
    for (int i = 1; i <= q;) {
        int j = i;
        int Sz = 0;
        f[b[i].c] = 1;
        while (j <= q && b[i].c == b[j].c) {
            int cur = 0;
            bad[a[b[j].x][b[j].y]].push_back(j);
            bad[a[b[j].x][b[j].y]].push_back(b[j].x);
            bad[a[b[j].x][b[j].y]].push_back(b[j].y);
            a[b[j].x][b[j].y] = b[j].c;
            Sz++;
            oks[b[j].x][b[j].y] = b[i].c;
            for (auto key : T) {
                int x = b[j].x + key.first, y = b[j].y + key.second;
                if (oks[x][y] == b[j].c) {
                    Sz -= (1^add(gett({x, y}), gett({b[j].x, b[j].y})));
                }
            }
            //cout << j << " " << Sz << endl;
            Add[j] += Sz;
            Add[j + 1] -= Sz;
            ++j;
        }
        for (int pos = i; pos < j; ++pos) {
            sz[gett({b[pos].x, b[pos].y})] = 0;
            cmp[gett({b[pos].x, b[pos].y})] = gett({b[pos].x, b[pos].y});
        }
        R[b[i].c] = j - 1;
        i = j;
    }
    //for (int i = 1; i <= q; ++i) cout << Add[i] << " ";
    //cout << endl;
    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= m + 1; ++j) oks[i][j] = -1;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) good[a[i][j]].push_back({i, j});
    int sum = 0;
    //for (int i = 0; i <= n * m; ++i) cout << cmp[i] << ' ';
    //cout << endl;
    for (int i = 0; i <= 2000000; ++i) {
        if (f[i] == 0) continue;
        //for (int j = 0; j <= n * m; ++j) cmp[j] = j, sz[j] = 0;
        int Sz = 0;
        for (auto key : good[i]) {
            oks[key.first][key.second] = i;
            Sz++;
            for (auto v : T) {
                int x = v.first + key.first, y = key.second + v.second;
                if (oks[x][y] == i) {
                    Sz -= (1^add(gett({x, y}), gett(key)));
                    //if (i == 0) cout << x << ' ' << y << " " << key.first << ' ' << key.second << endl;
                }
            }
        }
        //cout << i << " " << Sz << endl;
        int lst = q + 1;
        for (int j = (int)bad[i].size() - 3; j >= 0; j -= 3) {
            int t = bad[i][j], x = bad[i][j + 1], y = bad[i][j + 2];
            Add[t] += Sz;
            Add[lst] -= Sz;
            //cout << i << " " << t << " " << lst - 1 << " " << Sz << endl;
            Sz++;
            lst = t;
            oks[x][y] = i;
            //if (i == 1) cout << Sz << endl;
            for (auto v : T) {
                int xx = v.first + x, yy = v.second + y;
                if (oks[xx][yy] == i) {
                    Sz -= (1^add(gett({xx, yy}), gett({x, y})));
                }
            }
        }
        Add[R[i] + 1] += Sz;
        Add[lst] -= Sz;
        for (auto key : good[i]) {
            cmp[gett(key)] = gett(key);
            sz[gett(key)] = 0;
        }
        for (int j = 0; j < (int)bad[i].size(); j += 3) {
            int x = bad[i][j + 1], y = bad[i][j + 2];
            cmp[gett({x, y})] = gett({x, y});
            sz[gett({x, y})] = 0;
        }
    }
    for (int i = 1; i <= q; ++i) {
        sum += Add[i];
        cout << sum << '\n';
    }
    return 0;
}