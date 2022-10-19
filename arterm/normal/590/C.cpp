#include <bits/stdc++.h>


using namespace std;

#define y1 ladsafkl
#define y2 slkdfaslkfjla

#define x first
#define y second
#define mp make_pair

typedef long double ld;

const int M = 1010;
const int INF = 10000000;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
char symb[] = {'1', '2', '3'};

int n, m;
char a[M][M];
int d[3][M][M];

void read() {
    for (int i = 0; i < M; ++i)
        fill(a[i], a[i] + M, '#');

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

pair<int, int> q[M * M];
int qs, qf;
bool used[M][M];

void bfs(int c) {
    qs = qf = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            d[c][i][j] = INF;
            used[i][j] = false;
            if (a[i][j] == symb[c]) {
                d[c][i][j] = 0;
                q[qf++] = mp(i, j);
                used[i][j] = true;
            }
        }

    while (qs < qf) {
        int x = q[qs].x;
        int y = q[qs].y;
        ++qs;
        for (int k = 0; k < 4; ++k) {
            int tx = x + dx[k], ty = y + dy[k];
            if (a[tx][ty] != '#' && !used[tx][ty]) {
                d[c][tx][ty] = d[c][x][y] + (a[tx][ty] == '.' ? 1 : 0);
                used[tx][ty] = true;
                q[qf++] = mp(tx, ty);
            }
        }
    }
}

void kill() {
    int triple = INF;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != '#')
                triple = min(triple, d[0][i][j] + d[1][i][j] + d[2][i][j] - (a[i][j] == '.' ? 2 : 0));

    vector<int> ps(3, INF);
    int cur = 0;
    for (int x = 0; x < 3; ++x)
        for (int y = x + 1; y < 3; ++y) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    if (a[i][j] == symb[y])
                        ps[cur] = min(ps[cur], d[x][i][j]);
            cur++;
        }
    
    sort(ps.begin(), ps.end());
    
    int ind = ps[0] + ps[1];
    
    //cout << "triple = " << triple << endl;
    //cout << "ind = " << ind << endl;

    int ans = min(ind, triple);
    if (ans >= INF)
        cout << "-1\n";
    else
        cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(9);
    cout << fixed;

    read();
    for (int c = 0; c < 3; ++c)
        bfs(c);
    kill(); 
    return 0;
}