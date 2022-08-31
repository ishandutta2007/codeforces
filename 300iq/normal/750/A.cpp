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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i * 5;
        if (k + sum <= 240)
        {
            ans = i;
        }
    }
    cout << ans << '\n';
}