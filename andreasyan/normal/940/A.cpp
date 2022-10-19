#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n, d;
int a[N];

int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = n;
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
        {
            if (a[r] - a[l] <= d)
            {
                ans = min(ans, (l - 1) + (n - r));
            }
        }
    }
    cout << ans << endl;
    return 0;
}