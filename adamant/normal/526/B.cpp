#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k = 1 << n + 1;
    int a[k];
    for(int i = 2; i < k; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = k - 1; i > 1; i -= 2)
    {
        ans += abs(a[i] - a[i - 1]);
        a[i / 2] += max(a[i], a[i - 1]);
    }
    cout << ans << "\n";
    return 0;
}