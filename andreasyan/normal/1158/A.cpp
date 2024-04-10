#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if (a[n] > b[1])
    {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 0;
    bool z = false;
    for (int i = 1; i <= m; ++i)
    {
        if (b[i] == a[n])
        {
            z = true;
            break;
        }
    }
    if (z)
    {
        for (int i = 1; i <= m; ++i)
            ans += b[i];
        for (int i = 1; i < n; ++i)
            ans += (a[i] * 1LL * m);
    }
    else
    {
        for (int i = 1; i < m; ++i)
            ans += b[i];
        ans += a[n];

        ans += (a[n - 1] * 1LL * (m - 1));
        ans += b[m];

        for (int i = 1; i < n - 1; ++i)
            ans += (a[i] * 1LL * m);
    }
    cout << ans << endl;
    return 0;
}