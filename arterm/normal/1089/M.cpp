#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 10;

const int W = 37;
const int H = 160;

// const int W = 15;
// const int H = 15;

struct C {
    int x, y, z;
};

static_assert(W*H*H<=1000000, "oieansroierant");

int a[W][H][H];

int n;
int e[maxn][maxn];

void buildEdge(int u, int v, int h) {
    int x = u * 4;
    int y = h + 1;

    assert(a[x][y][h] == 0);
    a[x][y][h] = 0; ++x;
    a[x][y][h] = 0; ++x;

    forn(i, 7) {
        a[x][y][h] = 0; ++y;
    }
    cerr << x << " " << y << " " << h << endl;

    while (x > v * 4 + 2) {
        a[x][y][h] = 0; --x;
    }

    while (x < v * 4 + 2) {
        a[x][y][h] = 0; ++x;
    }

    while (y > 0) {
        a[x][y][h] = 0; --y;
    }

    a[x][y][h] = 0; --x;
    a[x][y][h] = 0; --x;
    assert(y == 0);
    assert(x == v*4);
}

void build() {
    forn(i, W) forn(j, H) forn(k, H) a[i][j][k] = 1;

    // build chafts
    forn(v, n) {
        int x = v * 4;
        forn(z, H) a[x][0][z] = 0;
    }

    // build stairs
    forn(v, n) {
        int x = v * 4;
        int y = 0, z = 0;
        while (y + 5 < H) {
            a[x][y][z] = 0;
            ++y;
            a[x][y][z] = 0;
            ++z;
        }
    }

    // set starts
    forn(v, n) {
        int x = v * 4;
        a[x][0][0] = 10 + v;
    }

    int h = 2;
    forn(i, n) forn(j, n) if (e[i][j]) {
        buildEdge(i, j, h);
        h += 2;
    }
}

int b[W][H][H];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int z) {
    if (b[x][y][z]) return;
    b[x][y][z] = 1;
    forn(i, 4) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if (tx < 0 || tx >= W || ty < 0 || ty >= H) continue;
        if (a[tx][ty][z] == 1) {
            if (a[x][y][z+1] != 1 && a[tx][ty][z+1] != 1) {
                dfs(tx, ty, z+1);
            }
        } else {
            int tz = z;
            while (tz > 0 && a[tx][ty][tz-1] != 1) --tz;
            dfs(tx, ty, tz);
        }
    }
}

void check() {
    forn(i, n) e[i][i] = 1;
    forn(k, n) forn(i, n) forn(j, n) e[i][j] |= e[i][k] & e[k][j];
    forn(v, n) {
        memset(b, 0, sizeof b);
        dfs(v*4, 0, 0);
        forn(u, n) cout << b[u*4][0][0] << " "; cout << endl;
    }
    cout << endl;
    forn(i, n) {
        forn(j, n) cout << e[i][j] << " ";
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("m.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    cin >> n;
    forn(i, n) forn(j, n) {
        cin >> e[i][j];
    }

    build();

    // check();
    // return 0;

    cout << W << " " << H << " " << H << endl;
    ford(z, H) {
        forn(i, H) {
            forn(j, W) {
                if (b[j][i][z]) cout << "+";
                else {
                    if (a[j][i][z] >= 10) cout << char('1' + a[j][i][z] - 10);
                    else if (a[j][i][z] == 0) cout << '.';
                    else cout << '#';
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}