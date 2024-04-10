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


ll n, i, j, k, ans, ans2, kol;
vector<ll> m, v, f, fo, stk, stkm;
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

void mul(ll k) {
    ans *= k;
    ans %= mod;
}

void prep() {
    f.push_back(1);
    stk.push_back(1);
    stkm.push_back(1);
    for (ll i = 1; i < 2 * n + 10; i++) {
        f.push_back(f.back() * i);
        f.back() %= mod;
        stk.push_back(stk.back() * (k - 1));
        stk.back() %= mod;
        stkm.push_back(stkm.back() * (k - 2));
        stkm.back() %= mod;
    }
    for (auto i : f)
        fo.push_back(obr(i, mod));
}

ll c(ll n, ll k) {
    ll res = 1;
    ll a = f[n];
    ll b = fo[k];
    ll c = fo[n - k];
    res *= a; res %= mod;
    res *= b; res %= mod;
    res *= c; res %= mod;
    return res;
}


void add(ll mn, ll mx, ll kol) {
    ll loc = 1;
    loc *= c(kol, mx);
    loc %= mod;
    loc *= c(kol - mx, mn);
    loc %= mod;
    loc *= stkm[kol - mn - mx];
    loc %= mod;
    ans2 += loc;
    ans2 %= mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ans = 1;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    ll pl = -1;
    for (ll i = 1; i < n; i++) {
        if (m[i] != m[i-1])
            pl = i;
    }
    if (pl == -1) {
        cout << 0;
        exit(0);
    }

    vector<ll> m2;
    for (ll i = pl; i < pl + n; i++)
        m2.push_back(m[i % n]);
    m = m2;
    for (ll i = 0; i < n; i++) {
        if (i < n - 1 && m[i] == m[i+1])
            mul(k);
        else
            kol++;
    }
//    cout << ans << endl;
    prep();
    for (ll i = 0; i <= kol; i++)
        for (ll j = i + 1; j <= kol; j++)
            if (i + j <= kol)
                add(i, j, kol);

//    cout << ans << ' ' << ans2 << endl;
    ans2 *= ans;
    ans2 %= mod;
    cout << ans2 << endl;


    return 0;
}