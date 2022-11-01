#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e5 + 10;
const int M = 1e3 + 10;

struct F {
    int b, p, num;

    bool operator < (const F a) const {
        if (b != a.b)
            return b > a.b;
        if (p != a.p)
            return p > a.p;
        return num > a.num;
    }
};

vector <F> a, b;

int ta[4 * N], tb[4 * N];

bool cmp(F a, F b) {
    if (a.p != b.p)
        return a.p < b.p;
    return a.num < b.num;
}

void builda(int v, int tl, int tr) {
    if (tl == tr) {
        ta[v] = a[tl].b;
        return;
    }
    int tm = (tl + tr) / 2;
    builda(2 * v, tl, tm);
    builda(2 * v + 1, tm + 1, tr);
    ta[v] = max(ta[2 * v], ta[2 * v + 1]);
}

void buildb(int v, int tl, int tr) {
    if (tl == tr) {
        tb[v] = b[tl].b;
        return;
    }
    int tm = (tl + tr) / 2;
    buildb(2 * v, tl, tm);
    buildb(2 * v + 1, tm + 1, tr);
    tb[v] = max(tb[2 * v], tb[2 * v + 1]);
}

int getMaxa(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr)
        return -INF;
    if (l <= tl && tr <= r)
        return ta[v];
    int tm = (tl + tr) / 2;
    return max(getMaxa(2 * v, tl, tm, l, r), getMaxa(2 * v + 1, tm + 1, tr, l, r));
}

int getMaxb(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr)
        return -INF;
    if (l <= tl && tr <= r)
        return tb[v];
    int tm = (tl + tr) / 2;
    return max(getMaxb(2 * v, tl, tm, l, r), getMaxb(2 * v + 1, tm + 1, tr, l, r));
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, c, d;
    cin >> n >> c >> d;

    set <F> a1, b1;

    fr(i, n) {
        int x, y;
        char t;
        cin >> x >> y >> t;
        if (t == 'C') {
            a.pb({x, y, i});
            a1.insert({x, y, (int)a.size() - 1});
        }
        else {
            b.pb({x, y, i});
            b1.insert({x, y, (int)b.size() - 1});
        }
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    if (a.size() >= 1) builda(1, 0, (int)a.size() - 1);
    if (b.size() >= 1) buildb(1, 0, (int)b.size() - 1);

    int ans = 0;
    int mx1 = -1, mx2 = -1;
    fr(i, a.size())
        if (a[i].p <= c)
            mx1 = max(mx1, a[i].b);
    fr(i, b.size())
        if (b[i].p <= d)
            mx2 = max(mx2, b[i].b);
    if (mx1 != -1 && mx2 != -1)
        ans = mx1 + mx2;

    int cur = (int)a.size() - 1;
    fr(i, a.size()) {
        while (cur > i && a[cur].p + a[i].p > c)
            cur--;
        //cout << i << " " << cur << endl;
        if (cur > i)
            ans = max(ans, a[i].b + getMaxa(1, 0, (int)a.size() - 1, i + 1, cur));
    }

    cur = (int)b.size() - 1;
    fr(i, b.size()) {
        while (cur > i && b[cur].p + b[i].p > d)
            cur--;
        if (cur > i)
            ans = max(ans, b[i].b + getMaxb(1, 0, (int)b.size() - 1, i + 1, cur));
    }

    cout << ans;
}