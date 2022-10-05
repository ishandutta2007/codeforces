#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j;
vector<pll> m;
vector<ll> p, rm;
vector<pair<pll, ll>> qr;
ll done;
vector<ll> ans;
bool viv = false;

vector<ll> t;
ll s;

void show() {
    for (ll i = 1; i < 2 * s; i++) {
        cout << t[i] << ' ';
        if (!((i) & (i+1)))
            cout << endl;
    }
    cout << "____ " << endl;
}

void build() {
    s = 1;
    while (s < n + 1)
        s <<= 1;
    t.resize(2 * s);
}

void prepare() {
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        qr.push_back({{a, b}, i});
    }
    sort(qr.begin(), qr.end());
    ans.resize(q, -1);

    build();
}

void add(ll pl) {
    pl += s;
    while (pl) {
        t[pl]++;
        pl >>= 1;
    }
}

ll find(ll v, ll l, ll r, ll k) {
    if (l == r)
        return r;
    ll mi = l + r >> 1;
    if (viv)
        cout << "I'm on " << v << " [" << l << "; " << r << "] and " << t[2*v] << endl;
    if (t[2*v] < k)
        return find(2*v+1, mi + 1, r, k - t[2*v]);
    return find(2*v, l, mi, k);
}

ll get(ll k) {
    if (viv)
        cout << "Hmmm " << find(1, 0, s-1, k) << endl;
    return find(1, 0, s-1, k);
}

void solve(pair<pll, ll> z) {
    while (done < z.F.F) {
        add(p[done]);
        done++;
    }
    if (viv) {
        cout << "done " << done << endl;
        show();
    }
    ll res = get(z.F.S);
    if (viv)
        cout << "Here get the ans on " << res << endl;
    ans[z.S] = rm[res];
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        rm.push_back(a);
        m.push_back({a, -i});
    }
    sort(m.rbegin(), m.rend());
    for (auto i : m)
        p.push_back(-i.S);
    prepare();
    for (auto i : qr)
        solve(i);

    for (auto i : ans)
        cout << i << '\n';



    return 0;
}