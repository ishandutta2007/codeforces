#include <bits/stdc++.h>
using namespace std;
const int N = 22;

int n, x, y;
int a[N];

int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 1, j = n; i <= n; ++i, --j)
    {
        if (i > j)
            break;
        if (i == j)
        {
            if (a[i] == 2)
                ans += min(x, y);
            break;
        }
        if (a[i] == 0 && a[j] == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] == 1 && a[j] == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] == a[j])
        {
            if (a[i] == 2)
                ans += (2 * min(x, y));
            continue;
        }
        if (a[i] == 0)
            ans += x;
        if (a[i] == 1)
            ans += y;
        if (a[j] == 0)
            ans += x;
        if (a[j] == 1)
            ans += y;
    }
    cout << ans << endl;
    return 0;
}