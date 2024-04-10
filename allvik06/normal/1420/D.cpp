#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mod = 998244353;

struct event {
    int x;
    bool f;
    event(int x, bool f) : x(x), f(f) {}
    event() {}
};

bool cmp(const event& a, const event& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.f < b.f;
}

ll binary_power(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll kek = binary_power(a, b / 2);
        return (kek * kek) % mod;
    }
    else return (a * binary_power(a, b - 1)) % mod;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> dp_last(n + 1), dp_not_last(n + 1);
    dp_last[0] = 1;
    vector <event> ev;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ev.emplace_back(l, true);
        ev.emplace_back(r + 1, false);
    }
    sort(ev.begin(), ev.end(), cmp);
    vector <ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
    ll ans = 0;
    int kol = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (ev[i].f) {
            ++kol;
            if (kol >= k) {
                ans += (((fact[kol - 1] * binary_power(fact[k - 1], mod - 2)) % mod) * binary_power(fact[kol - k], mod - 2)) % mod;
                ans %= mod;
            }
        }
        else {
            --kol;
        }
    }
    cout << ans;
}