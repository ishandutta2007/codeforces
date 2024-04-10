#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 2e5;
const ld EPS = 1e-8;
const ld INF = 1e9;

struct pt {
    ll x, y;
    pt operator - (const pt a) const {
        return {x - a.x, y - a.y};
    }
};

ll crossProduct(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

ll dotProduct(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}

pt a[N], b[N];

bool ptInAngle(pt a, pt b, pt c, pt t) {
    ll t1 = crossProduct(c - b, t - b);
    if (t1) t1 /= abs(crossProduct(c - b, t - b));
    ll t2 = crossProduct(t - b, a - b);
    if (t2) t2 /= abs(crossProduct(t - b, a - b));
    if (t1 * t2 < 0) return false;
    return true;
}

bool ptOnSeg(pt a, pt b, pt t) {
    if (t.x < a.x && t.x < b.x || t.y < a.y && t.y < b.y) return false;
    if (t.x > a.x && t.x > b.x || t.y > a.y && t.y > b.y) return false;
    return (b.x - t.x) * (t.y - a.y) == (t.x - a.x) * (b.y - t.y);
}

int main() {
    ld st = clock();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m;
    cin >> n;
    fr(i, n)
        cin>> a[i].x >> a[i].y;
    cin >> m;
    fr(i, m) {
        pt t;
        cin >> t.x >> t.y;
        ll r = n - 1, l = 1;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (ptInAngle(a[r], a[0], a[m], t))
                l = m;
            else
                r = m;
        }
        if (!ptInAngle(a[r], a[0], a[l], t) || !ptInAngle(a[0], a[l], a[r], t) || !ptInAngle(a[l], a[r], a[0], t)) {
            cout << "NO";
            return 0;
        }
        if (ptOnSeg(a[l], a[r], t) || l == 1 && ptOnSeg(a[0], a[l], t) || r == n - 1 && ptOnSeg(a[0], a[r], t)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";



}