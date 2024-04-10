#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll N = 2e5 + 2;
const ll INF = 2e9 + 10;
const ll ALPH = 300;
const ll MOD = 1e9 + 7;
const ll P = 29;

ll n, k, a1, b1, q;
ll a[N];
ll t1[4 * N], t2[4 * N];

void add1(ll v, ll tl, ll tr, ll x, ll pos) {
    if (tl == tr) {
        t1[v] += x;
        t1[v] = min(t1[v], a1);
        return;
    }
    ll tm = (tl+tr) /2 ;
    if (pos <= tm)
        add1(2 * v, tl, tm, x, pos);
    else
        add1(2 * v + 1, tm + 1, tr, x, pos);
    t1[v] = t1[2 * v] + t1[2 * v + 1];
}

void add2(ll v, ll tl, ll tr, ll x, ll pos) {
    if (tl == tr) {
        t2[v] += x;
        t2[v] = min(t2[v], b1);
        return;
    }
    ll tm = (tl + tr)/ 2;
    if (pos <= tm)
        add2(2 * v, tl, tm, x, pos);
    else
        add2(2 * v + 1, tm + 1, tr, x, pos);
    t2[v] = t2[2 * v] + t2[2 * v + 1];
}

ll sum1(ll v, ll tl, ll tr, ll l, ll r) {
    if (tl > r || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        return t1[v];
    ll tm = (tl + tr) / 2;
    return sum1(2 * v, tl, tm, l, r) + sum1(2 * v + 1, tm + 1, tr, l, r);
}

ll sum2(ll v, ll tl, ll tr, ll l, ll r) {
    if (tl > r || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        return t2[v];
    ll tm = (tl + tr)/ 2;
    return sum2(2 * v, tl, tm, l, r) + sum2(2 * v + 1, tm + 1, tr, l, r);
}

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    cin >> n >> k >> a1 >> b1 >> q;
    fr(i, q) {
        ll typ;
        cin >> typ;
        if (typ == 1) {
            ll x, pos;
            cin >> pos >> x;
            pos--;
            add1(1, 0, n - 1, x, pos);
            add2(1, 0, n - 1, x, pos);
        }
        else {
            ll p;
            cin >> p;
            p--;
            cout << (p >= 1 ? sum2(1, 0, n - 1, 0, p - 1) : 0) + (p + k <= n - 1 ? sum1(1, 0, n - 1, p + k, n - 1) : 0) << endl;
        }
    }
}