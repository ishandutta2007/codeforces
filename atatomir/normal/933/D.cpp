#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011
#define mod 1000000007

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

const ll def = 1000000;
const ll p2 = (mod + 1) / 2;
const ll p3 = poww(3, mod - 2);
const ll p6 = (p2 * p3) % mod;

ll m, i, x, y, sz, xx, k;
ll sum_full[maxN], sum_part[maxN], sum_extra[maxN];
ll ans;

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

ll gauss(ll a, ll b) {
    a %= mod;
    b %= mod;

    ll aux = (a + b) * (mod + b - a + 1);
    aux %= mod;
    aux *= p2;
    aux %= mod;
    return aux;
}

ll sum_squares(ll a, ll b) {
    a %= mod;
    b %= mod;

    ll aux1 = (b * (b + 1)) % mod;
    aux1 = (aux1 * (2 * b + 1)) % mod;

    ll aux2 = ((mod + a - 1) * a) % mod;
    aux2 = (aux2 * (2 * (mod + a - 1) + 1)) % mod;

    aux1 = (aux1 + mod - aux2);
    aux1 = (aux1 * p6) % mod;
    return aux1;
}

ll gauss_extra(ll a, ll b) {
    a %= mod;
    b %= mod;

    ll s1 = (mod + a * a - a);
    s1 %= mod;
    s1 *= p2;
    s1 %= mod;
    s1 *= (mod + b - a + 1);
    s1 %= mod;
    s1 = mod - s1;

    ll s2 = sum_squares(a, b) + gauss(a, b);
    s2 %= mod;
    s2 = (s2 * p2) % mod;
    return (s1 + s2) % mod;
}

void pre() {
    ll i, sz, p1, p2;

    sum_full[1] = sum_part[1] = sum_extra[1] = 1;
    for (i = 2; i <= def; i++) {
        p1 = (i - 1) * (i - 1);
        p2 = i * i;
        sz = p2 - p1;

        sum_part[i] = sum_part[i - 1] + gauss(1, sz) * (i - 1) + 1;
        sum_part[i] %= mod;
        sum_part[i] += (( ((p1 + 1) % mod) * (i - 1) + mod - sum_squares(1, i - 1)) % mod) * (sz % mod);
        sum_part[i] %= mod;

        sum_full[i] = sum_full[i - 1] + gauss(p1 + 1, p2) * (i - 1) + p2;
        sum_full[i] %= mod;

        sum_extra[i] = sum_extra[i - 1] + gauss_extra(p1 + 1, p2) * (i - 1);
        sum_extra[i] %= mod;
        sum_extra[i] += sum_full[i - 1] * (sz % mod) + p2;
        sum_extra[i] %= mod;
    }
}

void add_to_sol() {
    ll part, full, extra;
    ll dif_down, dif_up;

    while (k * k > sz) k--;
    dif_down = xx % mod;
    dif_up = (sz - k * k) % mod;

    //! add upper part
    full = sum_full[k] + gauss(k * k + 1, sz) * k;
    full %= mod;

    part = sum_part[k] + gauss(1, sz - k * k) * k;
    part %= mod;
    part += (((k * k + 1) * k + mod - sum_squares(1, k)) % mod) * (dif_up);
    part %= mod;

    extra = sum_extra[k] + gauss_extra(k * k + 1, sz) * k;
    extra %= mod;
    extra += sum_full[k] * (dif_up);
    extra %= mod;

    //! add lower part
    //full += part * xx;
    //full %= mod;

    extra += part * (xx % mod);
    extra %= mod;

    ans += extra;
    ans %= mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> m;
    pre();

    k = sqrt(m);
    while ((k + 1) * (k + 1) <= m) k++;

    for (x = 0; x * x < m; x++) {
        xx = x * x;
        sz = m - xx;

        add_to_sol();
    }

    ans *= 4LL;
    ans %= mod;

    ans += gauss_extra(1, m);
    ans %= mod;

    cout << ans;


    return 0;
}