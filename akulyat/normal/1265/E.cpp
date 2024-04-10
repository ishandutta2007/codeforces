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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7;


ll n, i, j, q, ans;
vector<ll> m, qr;
vector<ll> t, vals;
ll s;

vector<ll> seg;

set<pll> have;
unordered_set<ll> cp;
bool viv = false;

ll main_val(ll l, ll r);


long long obr(long long v, long long mod)
{
long long i = 0;
long long st = mod - 2;
vector<long long> bin;
long long l = 0;
while(st > 0)
    {
    bin.push_back(st & 1);
    st /= 2;
    l++;
    }

vector<long long> sq;
sq.push_back(v);
for (i = 1; i < l; i++)
    {
    long long s = sq.back();
    s *= s;
    s %= mod;
    sq.push_back(s);
    }

long long ans = 1;
for (i = 0; i < l; i++)
    if (bin[i])
        {
        ans *= sq[i];
        ans %= mod;
        }
return ans;
}

ll prob(ll val) {
    ll res = 100;
    res *= obr(val, mod);
    res %= mod;
    return res;
}

void st(vector<ll> p) {
    ld sum = 0;
    ll n = ml;
    for (ll i = 0; i < n; i++) {
        ll now = 0;
        ll steps = 0;
        while (now != p.size()) {
            if (rand() % 100 < p[now])
                now++;
            else
                now = 0;
            steps++;
        }
        sum += steps;
    }

    sum /= n;
    cout << "For ";
    for (auto i : p)
        cout << i << ' ';
    cout << " is ";
    cout << sum << endl;
}

void get(ll v) {
    if (v >= s)
        return;
    t[v] = t[2 * v] * t[2 * v + 1];
    t[v] %= mod;

    vals[v] = vals[2 * v] * t[2*v+1];
    vals[v] %= mod;
    vals[v] += vals[2*v+1];
    if (vals[v] >= mod)
        vals[v] %= mod;
}

void prepare() {
    s = 1;
    while (s < n)
        s <<= 1;
    t.resize(2 * s);
    vals.resize(2 * s);
    for (ll i = 0; i < n; i++)
        t[i+s] = prob(m[i]);

    for (ll i = n; i < s; i++)
        t[i+s] = 1;

    for (ll i = 0; i < s; i++)
        vals[i+s] = t[i+s];

    for (ll i = s - 1; i > 0; i--)
        get(i);

    have.insert({0, n});
    ans = main_val(0, n);
    cp.insert(0);
}

ll mul(ll l, ll r, ll v, ll tl, ll tr) {
    if (r < tl || tr < l)
        return 1;
    if (l <= tl && tr <= r)
        return t[v];
    ll tm = tl + tr >> 1;
    ll v1 = mul(l, r, 2*v, tl, tm);
    ll v2 = mul(l, r, 2*v + 1, tm + 1, tr);
    v1 *= v2;
    v1 %= mod;
    return v1;
}

void get_seg(ll l, ll r, ll v, ll tl, ll tr) {
    if (r < tl || tr < l)
        return;
    if (l <= tl && tr <= r) {
        seg.push_back(v);
        return;
    }
    ll tm = tl + tr >> 1;
    get_seg(l, r, 2*v, tl, tm);
    get_seg(l, r, 2*v+1, tm+1, tr);
}

ll main_val(ll l, ll r) {
    r--;
    seg.clear();
    get_seg(l, r, 1, 0, s-1);
    reverse(seg.begin(), seg.end());

    ll mul = 1;
    ll res = 0;
    for (auto v : seg) {
        res += mul * vals[v];
        res %= mod;

        mul *= t[v];
        mul %= mod;
    }
    return res;
}

void solve(ll pl) {
    if (cp.count(pl)) {
        cp.erase(pl);
        auto z = have.lower_bound({pl, -1});
        auto z2 = z;
        z2--;
        ll l = (*z2).F;
        ll r = (*z).S;

        if (viv) {
            cout << "______ I see ";
            cout << l << ' ';
            cout << pl << ' ';
            cout << r << '\n';
        }

        ans -= main_val(l, pl);
        ans -= main_val(pl, r);
        ans += main_val(l, r);

        have.erase({l, pl});
        have.erase({pl, r});
        have.insert({l, r});
    } else {
        cp.insert(pl);
        auto z = have.lower_bound({pl, -1});
        z--;
        ll l = (*z).F;
        ll r = (*z).S;

        ans -= main_val(l, r);
        ans += main_val(l, pl);
        ans += main_val(pl, r);

        have.erase({l, r});
        have.insert({l, pl});
        have.insert({pl, r});
    }
    if (viv) {
        cout << "Have\n";
        for (auto p : have) {
            cout << p.F << ' ' << p.S << "; ";
        }
        cout << endl;

        cout << "CP\n";
        for (auto p : cp) {
            cout << p << " ";
        }
        cout << endl;

    }

    ans %= mod;
    if (ans < 0)
        ans += mod;
    if (viv)
        cout << "___________________________ ";
    cout << ans << '\n';
}

void show() {
    cout << "Show" << endl;
    for (ll i = 1; i < 2*s; i++) {
        cout << t[i] << ' ';
        if (!(i & (i + 1)))
            cout << endl;
    }
    for (ll i = 1; i < 2*s; i++) {
        cout << vals[i] << ' ';
        if (!(i & (i + 1)))
            cout << endl;
    }
}

int main() {
//    viv = true;

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    q = 0;
    cin >> n;
   // cin >> q;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    qr.resize(q);
    for (auto &i : qr)
        cin >> i, i--;
    prepare();
    for (auto i : qr)
        solve(i);

    if (q == 0)
        cout << ans << endl;
    if (viv)
        show();

    return 0;
}