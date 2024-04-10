#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> f;
vector <int> l;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    ll cur = 1;
    for (ll i = 0; i < n - 1; i++)
        cur *= 2ll;
    for (ll i = 1; i <= n; i++)
    {
        if (m <= cur / 2ll)
            f.push_back(i);
        else
            l.push_back(i), m -= cur / 2;
        cur /= 2;
    }
    for (ll i = 0; i < (int)f.size(); i++)
        cout << f[i] << " ";
    for (ll i = (int)l.size() - 1; i >= 0; i--)
        cout << l[i] << " ";
}