#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ll n, k;
    cin >> n >> k;
    vector <ll> t;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
            {
                t.push_back(n / i);
            }
            k--;
            if (k == 0)
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    reverse(t.begin(), t.end());
    for (auto c : t)
    {
        k--;
        if (k == 0)
        {
            cout << c << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}