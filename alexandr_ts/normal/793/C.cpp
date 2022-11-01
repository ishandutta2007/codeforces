#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-15;

const int N = 3e5 + 10;
const int M = 1e3 + 10;

pair <ld, ld> a[N];

int rx[N], ry[N], vx[N], vy[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    fr(i, n) {
        cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
    }

    fr(i, n) {
        ld l = -INF, r = INF;
        if (vx[i] > 0) {
            ld t1 = max((ld)0, ((ld)x1 - rx[i]) / (ld)vx[i]);
            ld t2 = ((ld)x2 - rx[i]) / (ld)vx[i];
            l = max(l, t1);
            r = min(r, t2);
        }
        else if (vx[i] < 0) {
            ld t1 = max((ld)0, ((ld)x2 - rx[i]) / (ld)vx[i]);
            ld t2 = ((ld)x1 - rx[i]) / (ld)vx[i];
            l = max(l, t1);
            r = min(r, t2);
        }
        else if (vx[i] == 0) {
            if (rx[i] <= x1 || rx[i] >= x2)
                l = INF, r = -INF;
        }
        if (vy[i] > 0) {
            ld t1 = max((ld)0, ((ld)y1 - ry[i]) / (ld)vy[i]);
            ld t2 = ((ld)y2 - ry[i]) / (ld)vy[i];
            l = max(l, t1);
            r = min(r, t2);
        }
        else if (vy[i] < 0) {
            ld t1 = max((ld)0, ((ld)y2 - ry[i]) / (ld)vy[i]);
            ld t2 = ((ld)y1 - ry[i]) / (ld)vy[i];
            l = max(l, t1);
            r = min(r, t2);
        }
        else if (vy[i] == 0) {
            if (ry[i] <= y1 || ry[i] >= y2)
                l = INF, r = -INF;
        }
        if (l > r - EPS) {
            cout << -1;
            return 0;
        }
        a[i] = mp(l, r);
    }

    ld mxl = -INF, mnr = INF;
    fr(i, n)
        mxl = max(mxl, a[i].first), mnr = min(mnr, a[i].second);
    if (mxl > mnr - EPS)
        cout << -1;
    else
        cout << fixed << setprecision(12) << max((ld)0, mxl);
}