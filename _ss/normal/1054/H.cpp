#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vll multiply(vll const& a, vll const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vll result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

const int N = 1e5 + 10;
const int mod = 490019, phi_mod = 2 * 491 * 499, R = 459087, R2 = 398203; // R2 % 499 = 1

void add(ll &x, ll y)
{
    x += y;
    if (x >= mod) x -= mod;
}

int Phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    if (n > 1) res -= res / n;
    return res;
}

ll cnt[phi_mod];

void solve(vector<pii> vta, vector<pii> vtb, int mod_deg, ll cof)
{
    if (mod_deg == 1)
    {
        int sum_a = 0, sum_b = 0;
        for (pii pr : vta) sum_a += pr.se;
        for (pii pr : vtb) sum_b += pr.se;
        cnt[0] = (cnt[0] + (ll)sum_a * sum_b) % mod;
        return;
    }
    int phi = Phi(mod_deg);
    vi id(mod_deg, 1e9), val(phi);
    int root = R % mod_deg;
    if (mod_deg % (phi_mod / 2))
    {
        for (int i = 0, x = 1; i < phi; ++i)
        {
            val[i] = x;
            id[x] = i;
            x = (ll)x * root % mod_deg;
        }
        vll vt1(phi, 0), vt2(phi, 0);
        for (pii pr : vta) add(vt1[id[pr.fi % mod_deg]], pr.se);
        for (pii pr : vtb) add(vt2[id[pr.fi % mod_deg]], pr.se);
        vll vt3 = multiply(vt1, vt2);
        for (int i = phi; i < (int)vt3.size(); ++i) (vt3[i - phi] += vt3[i]) %= mod;
        for (int i = 0; i < phi; ++i)
            if (vt3[i]) add(cnt[val[i] * cof % phi_mod], vt3[i]);
    }
    else
    {
        /*for (pii pa : vta)
            for (pii pb : vtb)
                add(cnt[(ll)pa.fi * pb.fi * cof % phi_mod], pa.se * pb.se % mod);*/
        int root2 = R2 % mod_deg;
        for (int i = 0, x = 1; i < phi / 2; ++i)
        {
            val[i] = x;
            assert(id[x] == 1e9);
            id[x] = i;
            x = (ll)x * root % mod_deg;
        }
        for (int i = phi / 2, x = root2; i < phi; ++i)
        {
            val[i] = x;
            assert(id[x] == 1e9);
            id[x] = i;
            x = (ll)x * root % mod_deg;
        }
        vll vt1[2], vt2[2];
        vt1[0].resize(phi / 2);
        vt1[1].resize(phi / 2);
        vt2[0].resize(phi / 2);
        vt2[1].resize(phi / 2);
        for (pii pr : vta)
        {
            int tmp = id[pr.fi % mod_deg];
            if (tmp < phi / 2) add(vt1[0][tmp], pr.se);
            else add(vt1[1][tmp - phi / 2], pr.se);
        }
        for (pii pr : vtb)
        {
            int tmp = id[pr.fi % mod_deg];
            if (tmp < phi / 2) add(vt2[0][tmp], pr.se);
            else add(vt2[1][tmp - phi / 2], pr.se);
        }
        for (int i = 0; i <= 1; ++i)
            for (int j = 0; j <= 1; ++j)
            {
                ll cur_cof = cof;
                for (int t = 1; t <= i + j; ++t) cur_cof = cur_cof * root2 % phi_mod;
                vll vt3 = multiply(vt1[i], vt2[j]);
                for (int t = phi / 2; t < (int)vt3.size(); ++t) (vt3[t - phi / 2] += vt3[t]) %= mod;
                for (int t = 0; t < phi / 2; ++t)
                    if (vt3[t]) add(cnt[val[t] * cur_cof % phi_mod], vt3[t]);
            }
    }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    vi a(phi_mod, 0), b(phi_mod, 0);
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 0, x; i < n; ++i) cin >> x, (a[(ll)i * i % phi_mod] += x) %= mod;
    for (int j = 0, x; j < m; ++j) cin >> x, (b[(ll)j * j * j % phi_mod] += x) %= mod;
    map<int, vector<pii> > sa, sb;
    for (int i = 0; i < phi_mod; ++i)
    {
        int g = __gcd(i, phi_mod);
        if (a[i]) sa[g].eb(i / g, a[i]);
        if (b[i]) sb[g].eb(i / g, b[i]);
    }
    for (auto i : sa)
        for (auto j : sb)
            solve(i.se, j.se, phi_mod / __gcd((ll)phi_mod, (ll)i.fi * j.fi), (ll)i.fi * j.fi);
    ll res = 0, pw = 1;
    for (int i = 0; i < phi_mod; ++i)
    {
        res = (res + pw * cnt[i]) % mod;
        pw = pw * c % mod;
    }
    cout << res;
    return 0;
}