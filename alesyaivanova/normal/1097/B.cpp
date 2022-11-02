#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                sum += a[i];
            else
                sum -= a[i];
        }
        if (abs(sum) % 360 == 0)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}