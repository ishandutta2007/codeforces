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

const int maxN = 100011;
const ll mod = 1000000009;

ll n, k, a, b, inv_a, inv_b, i, sum, aux, act_a, act_b, step_a, step_b, step, cnt, ans;
string s;

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> a >> b >> k;
    cin >> s;

    inv_a = poww(a, mod - 2);
    inv_b = poww(b, mod - 2);

    act_a = poww(a, n);
    act_b = 1;

    for (i = 0; i < k; i++) {
        if (s[i] == '+')
            sum += ((act_a * act_b) % mod);
        else
            sum += mod - ((act_a * act_b) % mod);

        sum %= mod;
        act_a = (act_a * inv_a) % mod;
        act_b = (act_b * b) % mod;
    }

    step_a = poww(inv_a, k);
    step_b = poww(b, k);
    step = (step_a * step_b) % mod;

    cnt = (n + 1) / k;

    if (step != 1)
        aux = (mod + poww(step, cnt) - 1) * poww(step + mod - 1, mod - 2);
    else
        aux = cnt;
    aux %= mod;

    ans = (sum * aux) % mod;
    printf("%lld", ans);

    return 0;
}