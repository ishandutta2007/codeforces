#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 103;
const int N = 1e6 + 10;

struct pt {
    int x, y, s;
} a[N];

int d[12][M][M];

int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, q, c;
    cin >> n >> q >> c;
    fr(i, n) {
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].s);
        //cin >> a[i].x >> a[i].y >> a[i].s;
    }

    frab(c1, 0, c + 1) {
        fr(i, n)
            d[c1][a[i].x][a[i].y] += (a[i].s + c1) % (c + 1);
        frab(i, 1, M)
            frab(j, 1, M)
                d[c1][i][j] = d[c1][i][j] - d[c1][i - 1][j - 1] + d[c1][i - 1][j] +
                    d[c1][i][j - 1];
    }

    fr(i1, q) {
        int x1, y1, x2, y2, t;
        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
        t %= (c + 1);
        int ans = d[t][x2][y2] + d[t][x1 - 1][y1 - 1] -
            d[t][x2][y1 - 1] - d[t][x1 - 1][y2];
        printf("%d\n", ans);
    }
}