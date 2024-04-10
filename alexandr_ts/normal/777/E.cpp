#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e9 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

struct Ring {
    ll a, b, h;
} a[N];

bool cmp1(Ring a, Ring b) {
    if (a.b != b.b)
        return a.b < b.b;
    else
        return a.a < b.a;
}

ll t[4 * N];

ll getMax(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return -INF;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return max(getMax(2 * v, tl, tm, l, r), getMax(2 * v + 1, tm + 1, tr, l, r));
}

void upd(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        upd(2 * v, tl, tm, pos, val);
    else
        upd(2 * v + 1, tm + 1, tr, pos, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

ll ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].a >> a[i].b >> a[i].h;
    }
    sort(a, a + n, cmp1);
    fr(i, n) {
        int l = -1, r = i;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m].b > a[i].a)
                r = m;
            else
                l = m;
        }
        if (a[r].b > a[i].a && r < i)
            ans[i] = a[i].h + getMax(1, 0, n - 1, r, i - 1);
        else
            ans[i] = a[i].h;
        upd(1, 0, n - 1, i, ans[i]);
    }
    cout << *max_element(ans, ans + n);
}