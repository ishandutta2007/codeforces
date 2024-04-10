#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 3e5;
const ll MOD = 1e9 + 7;
const ll P = 11;

ll pows[N];
ll a[N], pref[N];
ll t[4 * N], add[4 * N];

void prec(ll n) {
    pows[0] = 1;
    frab(i, 1, n + 1)
        pows[i] = pows[i - 1] * P % MOD;
    fr(i, n + 1)
        pref[i] = ((i ? pref[i - 1] : 0) + pows[i]) % MOD;
    fill(add, add + 4 * n, -1);
}

void update(ll v, ll tl, ll tr) {
    ll tm = (tl + tr) / 2;
    t[v] = (t[2 * v] * pows[tr - tm] + t[2 * v + 1]) % MOD;
}

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    ll tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    update(v, tl, tr);
}

void push(ll v, ll tl, ll tr) {
    if (add[v] == -1)
        return;
    t[v] = add[v] * pref[tr - tl] % MOD;
    if (tl != tr)
        add[2 * v] = add[2 * v + 1] = add[v];
    add[v] = -1;
}

void change(ll v, ll tl, ll tr, ll l, ll r, ll x) {
    push(v, tl, tr);
    if (tl > r || tr < l)
        return;
    if (tl >= l && tr <= r) {
        add[v] = x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    change(2 * v, tl, tm, l, r, x);
    change(2 * v + 1, tm + 1, tr, l, r, x);
    update(v, tl, tr);
}

ll check(ll v, ll tl, ll tr, ll l, ll r) {
    push(v, tl, tr);
    if (tl > r || tr < l)
        return 0;
    if (tl >= l && tr <= r)
        return t[v] * pows[r - tr] % MOD;
    ll tm = (tl + tr) / 2;
    return (check(2 * v, tl, tm, l, r) + check(2 * v + 1, tm + 1, tr, l, r)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    ll typ, l, r, x, n, m, k;
    cin >> n >> m >> k;

    prec(n);

    fr(i, n) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    build(1, 0, n - 1);

    fr(i, m + k) {
        cin >> typ >> l >> r >> x;
        l--, r--;
        if (typ == 1)
            change(1, 0, n - 1, l, r, x);
        else
            if (check(1, 0, n - 1, l + x, r) == check(1, 0, n - 1, l, r - x))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
    }
}