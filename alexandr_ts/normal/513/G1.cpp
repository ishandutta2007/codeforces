#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, k;

ll inv(ll a[])
{
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = i; j < n; j++)
            if (a[i] > a[j])
                ans += 1;
   // cout << ans << endl;
    return ans;
}

ll rec(ll a[], ll q)
{
    //for (ll i = 0; i < n; i++)
      //  cout << a[i] << " ";cout << endl;
    if (q >= k)
        return inv(a);
    ld ans = 0;
    for (ll i = 0; i < n; i++)
        for (ll j = i; j < n; j++)
        {
            ll tmp[n];
            fill(tmp, tmp + n, 0);
            for (ll t = 0; t < n; t++)
                tmp[t] = a[t];
            reverse(tmp + i, tmp + j + 1);
            ans += rec(tmp, q + 1);
        }
    return ans;
}

ll a[10];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll fact;
    fact = (n * (n - 1)) / 2 + n;
    ll tf = fact;
    for (ll i = 1; i < k; i++)
        fact *= tf;
    //ld ans = ;
    //cout << rec(a, 0);
    ld ans = (ld)rec(a, 0) / (ld)fact;
    cout << setprecision(12) << ans;
}