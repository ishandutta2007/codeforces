#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void rec(ll l, ll r, ll k, int num)
{
    ll m = (l + r) / 2;
    if (k == m)
    {
        cout << num << ' ';
        return;
    }
    else
    {
        if (k > (m - l + 1))
        {
            k -= (m - l + 1);
        }
        rec(l, m - 1, k, num - 1);
    }
}


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
    ll k;
    cin >> k;
    ll len = 0;
    for (int i = 0; i < n; i++)
    {
        len = len * 2 + 1;
    }
    rec(1, len, k, n);
}