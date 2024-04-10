#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[1000000];
ll b[1000000];
ll c[1000000];
ll d[1000000];

string s;

int main()
{
    ll n;
    cin >> n;
    ll sm = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sm += a[i];
    }
    b[0] = a[0];
    for (ll i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];

    c[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--)
        c[i] = c[i + 1] + a[i];

    if (sm % 3 != 0)
    {
        cout << 0;
        return 0;
    }
    ll m = sm / 3;
    ll qua = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        d[i] = qua;
        if (c[i + 1] == m && i < n - 1)
            d[i]--;
        if (c[i] == m)
            qua++;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        if (b[i] == m)
    {
        ans += d[i];
    }
    cout << ans << endl;
    /*for (int i = 0; i < n; i++)
        cout << b[i] << " " ;cout << endl;
        for (int i = 0; i < n; i++)
        cout << c[i] << " " ;cout << endl;
            for (int i = 0; i < n; i++)
        cout << d[i] << " " ;cout << endl;*/
    return 0;
}