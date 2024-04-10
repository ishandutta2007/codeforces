#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << n << " " << n;
        return 0;
    }
    int mi = max(0ll, n - m * 2);
    int left = 1;
    int right = n;
    while (right - left > 1)
    {
        int k = (left + right) / 2;
        if (k * (k - 1) / 2 >= m)
            right = k;
        else
            left = k;
    }
    int ma = max(0ll, n - right);
    cout << mi << " " << ma;
}