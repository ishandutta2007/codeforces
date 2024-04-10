#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 1000;
const int LOG = 10;

int s[N][LOG][N][LOG];
int a[N][N];
int d[N][N];

void calcDp(int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                if (min(i, j) == 0)
                    d[i][j] = 1;
                else
                    d[i][j] = 1 + min({d[i][j - 1], d[i - 1][j], d[i - 1][j - 1]});
            }
        }
}

void calcSparse(int n, int m) {
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
            s[x][0][y][0] = d[x][y];

    for (int px = 1; (1 << px) <= n; px++)
        for (int x = 0; x + (1 << px) - 1 < n; x++)
            for (int y = 0; y < m; y++)
                s[x][px][y][0] = max(s[x][px - 1][y][0],
                    s[x + (1 << (px - 1))][px - 1][y][0]);
    for (int px = 0; (1 << px) <= n; px++)
        for (int x = 0; x + (1 << px) - 1 < n; x++)
            for (int py = 1; (1 << py) <= m; py++)
                for (int y = 0; y + (1 << py) - 1 < m; y++) {
                    s[x][px][y][py] = max(s[x][px][y][py - 1],
                        s[x][px][y + (1 << (py - 1))][py - 1]);
                }
}

int sz[N + 1];

void solve() {
    int n, m;
    cin >> n >> m;
    //scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 2; i <= N; i++)
        sz[i] = sz[i / 2] + 1;


    calcDp(n, m);

    calcSparse(n, m);

    int q;
    cin >> q;
    //scanf("%d", &q);
    int x1, x2, y1, y2;
    for (int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        //scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--, y1--, x2--, y2--;
        int tl = 0, tr = min(x2 - x1, y2 - y1) + 2;
        while (tr - tl > 1) {
            int tm = (tl + tr) / 2;

            int x0 = x1 + tm - 1;
            int y0 = y1 + tm - 1;
            int px = sz[x2 - x0 + 1];
            int py = sz[y2 - y0 + 1];

            int x3 = (x2 + 1) - (1 << px);
            int y3 = (y2 + 1) - (1 << py);

            int mx = max({
                             s[x0][px][y0][py],
                             s[x0][px][y3][py],
                             s[x3][px][y0][py],
                             s[x3][px][y3][py]
                         });
            if (mx >= tm)
                tl = tm;
            else
                tr = tm;
        }
        cout << tl << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();
}