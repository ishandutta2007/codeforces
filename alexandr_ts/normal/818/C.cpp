#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 2;

struct sofa {
    int x, y;
    bool pos;
} a[N];

int lh[N], lv[N], rh[N], rv[N], th[N], tv[N], bh[N], bv[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int d, n, m;
    cin >> d >> n >> m;
    fr(i, d) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (y1 == y2)
            a[i].pos = 0;
        else
            a[i].pos = 1;
        a[i].x = x1;
        a[i].y = y1;

        if (a[i].pos == 0) {
            lh[x1]++;
            rh[x1]++;
            bh[y1]++;
            th[y1]++;
        }
        else {
            lv[x1]++;
            rv[x1]++;
            bv[y1]++;
            tv[y1]++;
        }
    }

    frab(i, 1, max(n, m) + 2) lh[i] += lh[i - 1];
    for (int i = max(n, m) + 1; i >= 0; i--) rh[i] += rh[i + 1];
    frab(i, 1, max(n, m) + 2) th[i] += th[i - 1];
    for (int i = max(n, m) + 1; i >= 0; i--) bh[i] += bh[i + 1];

    frab(i, 1, max(n, m) + 2) lv[i] += lv[i - 1];
    for (int i = max(n, m) + 1; i >= 0; i--) rv[i] += rv[i + 1];
    frab(i, 1, max(n, m) + 2) tv[i] += tv[i - 1];
    for (int i = max(n, m) + 1; i >= 0; i--) bv[i] += bv[i + 1];

    int cl, cr, ct, cb;
    cin >> cl >> cr >> ct >> cb;

    fr(i, d) {
        if (a[i].pos == 0) {
            int cl1 = lh[a[i].x] + lv[a[i].x] - 1;
            int cr1 = rh[a[i].x] + rv[a[i].x + 1] - 1;
            int ct1 = th[a[i].y - 1] + tv[a[i].y - 1];
            int cb1 = bh[a[i].y + 1] + bv[a[i].y];
            //cout << cl1 << " " << cr1 << " " << ct1 << " " << cb1 << endl;
            if (cl1 == cl && cr1 == cr && ct1 == ct && cb1 == cb) {
                cout << i + 1;
                return 0;
            }
        }
        else {
            int cl1 = lh[a[i].x - 1] + lv[a[i].x - 1];
            int cr1 = rh[a[i].x] + rv[a[i].x + 1];
            int ct1 = th[a[i].y] + tv[a[i].y] - 1;
            int cb1 = bh[a[i].y + 1] + bv[a[i].y] - 1;
            if (cl1 == cl && cr1 == cr && ct1 == ct && cb1 == cb) {
                cout << i + 1;
                return 0;
            }
        }
    }
    cout << -1;
}