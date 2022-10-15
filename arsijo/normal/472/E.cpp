#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
#define x first
#define y second
#define Point pair<int, int   >
typedef long long ll;
typedef pair<int, int
        > ii;
typedef pair<ii, ii> iii;
typedef long double ld;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e5 + 1;
#endif

int n, m, a[30][30], b[30][30], X[] = { 0, 1, 0, -1, -1, 1, -1, 1 }, Y[] = { 1, 0, -1,
        0, 1, 1, -1, -1 }, x, y;
ii previ[30][30], d[1000];
bool setted[30][30];
vector<ii> ans;

void check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != b[i][j])
                return;
    cout << ans.size() - 1 << endl;
    for(int i = 0; i < (int) ans.size(); i++){
        cout << (ans[i].first + 1) << " " << (ans[i].second + 1) << endl;
    }
    exit(0);
}

void update(ii p) {
    int t = a[p.x][p.y];
    a[p.x][p.y] = a[x][y];
    a[x][y] = t;
    ans.push_back(p);
    x = p.x;
    y = p.y;
}

void sorry() {
    cout << -1;
    exit(0);
}

void go(int p, int q) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            previ[i][j] = make_pair(-1, -1);

    int l = 0, r = 0;
    d[0] = make_pair(x, y);
    while (l <= r) {
        int x1 = d[l].x;
        int y1 = d[l].y;
        l++;
        for (int i = 0; i < 8; i++) {
            int x2 = x1 + X[i];
            int y2 = y1 + Y[i];
            if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m && !setted[x2][y2]
                    && previ[x2][y2] == Point(-1, -1)) {
                previ[x2][y2] = Point(x1, y1);
                d[++r] = Point(x2, y2);
            }
        }
    }
    Point po = Point(p, q);
    l = 0;
    Point end = Point(x, y);
    while (po != end) {
        d[l++] = po;
        po = previ[po.x][po.y];
    }

    while (l != 0) {
        po = d[--l];
        update(po);
    }
}

void swapA(Point p1, Point p2) {
    Point p = p1;
    while (true) {
        go(p.x, p.y);
        p = ans[ans.size() - 2];
        if (p == p2) {
            return;
        }
        setted[p.x][p.y] = true;
        go(p2.x, p2.y);
        setted[p.x][p.y] = false;
    }
}

void solve(int x1, int y1) {
    go(x1, y1);
    Point p = Point(-1, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i != x1 || j != y1) && !setted[i][j] && a[i][j] == b[x1][y1])
                p = Point(i, j);
    if (p == Point(-1, -1))
        sorry();
    swapA(p, Point(x1, y1));
    setted[x1][y1] = true;
}

int main() {

    sync;

    int q = 0;
    q = scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            q = scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            q = scanf("%d", &b[i][j]);
    }

    if (n == 1 || m == 1) {

        if (n == 1) {

            int l = -1, r = -1;
            for (int i = 0; i < m; i++)
            if (a[0][i] != b[0][i]) {
                if (l == -1)
                l = i;
                r = i;
            }
            if (a[0][l] == b[0][r]) {
                bool ok = true;
                for (int i = l; i < r; i++) {
                    if (b[0][i] != a[0][i + 1])
                    ok = false;
                }
                if (ok) {
                    for (int i = l; i <= r; i++) {
                        a[0][i] = b[0][i];
                        ans.push_back(Point(0, i));
                    }
                    check();
                }
            } else if (a[0][r] == b[0][l]) {
                bool ok = true;
                for (int i = l + 1; i <= r; i++) {
                    if (b[0][i] != a[0][i - 1])
                    ok = false;
                }
                if (ok) {
                    for (int i = l; i <= r; i++) {
                        int j = r - (i - l);
                        a[0][j] = b[0][j];
                        ans.push_back(Point(0, j));
                    }
                    check();
                }
            }

        } else {

            int l = -1, r = -1;
            for (int i = 0; i < n; i++)
            if (a[i][0] != b[i][0]) {
                if (l == -1)
                l = i;
                r = i;
            }
            if (a[l][0] == b[r][0]) {
                bool ok = true;
                for (int i = l; i < r; i++) {
                    if (b[i][0] != a[i + 1][0])
                    ok = false;
                }
                if (ok) {
                    for (int i = l; i <= r; i++) {
                        a[i][0] = b[i][0];
                        ans.push_back(Point(i, 0));
                    }
                    check();
                }
            } else if (a[r][0] == b[l][0]) {
                bool ok = true;
                for (int i = l + 1; i <= r; i++) {
                    if (b[i][0] != a[i - 1][0])
                    ok = false;
                }
                if (ok) {
                    for (int i = l; i <= r; i++) {
                        int j = r - (i - l);
                        a[j][0] = b[j][0];
                        ans.push_back(Point(j, 0));
                    }
                    check();
                }
            }

        }
        sorry();
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (a[i][j] == b[n - 1][m - 1]) {
        x = i;
        y = j;
    }

    ans.push_back(Point(x, y));

    for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m; j++)
    solve(i, j);
    for (int i = 0; i < m - 1; i++) {
        solve(n - 2, i);
        solve(n - 1, i);
    }
    check();

    if (x == n - 1) {
        update(Point(x - 1, y));
    } else {
        update(Point(x + 1, y));
    }
    check();

    sorry();

}