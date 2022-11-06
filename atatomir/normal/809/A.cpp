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

#define mod 1000000007
#define maxN 300011

int n, i;
ll v[maxN];
ll pows[maxN];
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> v[i];
    sort(v + 1, v + n + 1);

    pows[0] = 1;
    for (i = 1; i <= n; i++) pows[i] = (pows[i - 1] << 1) % mod;

    for (i = 1; i <= n; i++) {
        ll le = i - 1;

        if (le > 0)
            ans += (v[i] * (mod + pows[le] - 1)) % mod;

        ll ri = n - i;
        if (ri > 0)
            ans -= (v[i] * (mod + pows[ri] - 1)) % mod;

        ans += mod;
        ans %= mod;
    }

    cout << ans;

    return 0;
}