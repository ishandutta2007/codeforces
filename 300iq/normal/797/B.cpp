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
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    int mn = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            sum += a[i];
            if (a[i] % 2 == 1)
            {
                mn = min(mn, a[i]);
            }
        }
        else
        {
            if ((-a[i]) % 2 == 1)
            {
                mn = min(mn, -a[i]);
            }
        }
    }
    if (sum % 2 == 1)
    {
        cout << sum << '\n';
    }
    else
    {
        cout << sum - mn << '\n';
    }
}