#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll N = 3 * 1e5 + 1;
const ll M = 1e3;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

ll d[4 * N];
ll a[N];

void build(ll v, ll tl, ll tr) {
    if (tr > tl) {
        build(2 * v, tl, (tl + tr) / 2);
        build(2 * v + 1, (tl + tr) / 2 + 1, tr);
        d[v] = d[2 * v] | d[2 * v + 1];
    }
    else
        d[v] = a[tl];
}

ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    ll tm = (tl + tr) / 2;
    if (tl > r || tr < l)
        return 0;
    if (tl >= l && tr <= r)
        return d[v];
    return sum(2 * v, tl, tm, l, r) | sum(2 * v + 1, tm + 1, tr, l, r);
}

void update(ll v, ll tl, ll tr, ll pos, ll x) {
    ll tm = (tl + tr) / 2;
    if (tl > pos || tr < pos)
        return;
    if (tl == tr) {
        d[v] = x;
        return;
    }
    if(tm < pos)
        update(2 * v + 1, tm + 1, tr, pos, x);
    else
        update(2 * v, tl, tm, pos, x);
    d[v] = d[2 * v] | d[2 * v + 1];
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll n, k, x, curans = -1;
    cin >> n >> k >> x;
    fr(i, n)
        cin >> a[i];
    build(1, 0,n - 1);
    fr(j, n) {
        ll mx = -INF;
        ll p = 0;
        fr(i, k)
            a[j] *= x;
        update(1, 0, n - 1, j, a[j]);
        ll ans = 0;
        ans = d[1];
        fr(i, k)
            a[j] /= x;
        update(1, 0, n - 1, j, a[j]);
        curans = max(curans, ans);
    }

    cout << curans;

}