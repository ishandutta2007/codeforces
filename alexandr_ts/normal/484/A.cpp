#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << b << endl;
            continue;
        }
        ll k = 0;
        for (ll j = 1; j < (1ll << 62ll); j <<= 1ll)
            if ((a xor b) & j)
                k = j;
        ll tmp = 1, pw = 0;
        while (!(tmp & k) && k != 0)
            tmp <<= 1ll, pw++;
        ll ans = ((a >> pw) << pw) + k - 1;
        if (__builtin_popcountll(ans) < __builtin_popcountll(b))
            cout << b << endl;
        else
            cout << ans << endl;
       // cout << __builtin_popcountll(ans) << " " << __builtin_popcountll(b) << endl;
    }
}