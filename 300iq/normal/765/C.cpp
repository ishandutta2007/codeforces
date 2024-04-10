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
    int k, a, b;
    cin >> k >> a >> b;
    if (a < k && b < k)
    {
        cout << -1 << '\n';
        return 0;
    }
    if (a / k == 0 && b % k)
    {
        cout << -1 << '\n';
        return 0;
    }
    if (a % k && b / k == 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << a / k + b / k << '\n';
}