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


ll n, i, j, ans;
vector<ll> m;
vector<ll> q, c, o;
vector<ll> f, of;
string s;
bool viv = false;

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

void prepare() {
    q.push_back(0);
    c.push_back(0);
    o.push_back(0);
    for (auto i : s) {
        q.push_back(q.back());
        o.push_back(o.back());
        c.push_back(c.back());
        if (i == '?')
            q.back()++;
        if (i == '(')
            o.back()++;
        if (i == ')')
            c.back()++;
    }

    f.push_back(1);
    for (ll i = 1; i < 10 * kk; i++)
        f.push_back(f.back() * i), f.back() %= mod;
    for (auto i : f)
        of.push_back(obr(i, mod));
}

ll C(ll n, ll k) {
    if (k < 0 || k > n)
        return 0;
    ll res = 1;
    res *= f[n];
    res %= mod;
    res *= of[k];
    res %= mod;
    res *= of[n - k];
    res %= mod;
    return res;
}

void solve(ll kol) {
    ll lq1 = q[kol];
    ll lc1 = c[kol];
    ll lo1 = o[kol];
    ll lq2 = q.back() - lq1;
    ll lc2 = c.back() - lc1;
    ll lo2 = o.back() - lo1;

    if (viv) {
        cout << kol << ": ";
        cout << lq1 << ' ';
        cout << lo1 << ' ';
        cout << lc1 << ' ';
        cout << lq2 << ' ';
        cout << lo2 << ' ';
        cout << lc2 << ' ';
        cout << endl;
    }

    ll lans = 0;
    for (ll i = 0; i <= n; i++) {
        if (s[kol - 1] != ')' && s[kol] != '(' || true) {
            ll vars = 1;
            ll val1 = lq1;
            ll val2 = lq2;
/**
            if (s[kol - 1] == '?')
                val1--;
            if (s[kol] == '?')
                val1--;
**/
            vars *= C(lq1, i - lo1);
            vars *= C(lq2, i - lc2);
            vars %= mod;
            lans += vars * i;
            lans %= mod;
            if (viv)
                cout << "On " << kol << ' ' << i << " is " << vars << endl;
        }
    }
    lans %= mod;
    ans += lans;

    if (viv)
        cout << kol << " first give: " << lans << endl;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    prepare();

    for (ll i = 1; i < n; i++)
        solve(i);

    ans %= mod;
    cout << ans << endl;

    return 0;
}