#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 0;
    int k = n / 2;
    if (a[k] == s)
        cout << 0;
    else if (a[k] < s)
    {
        for (int e = k; e < n; e++)
        {
            if (a[e] >= s)
                break;
            ans += s - a[e];
        }
        cout << ans;
    }
    else
    {
        for (int e = k; e >= 0; e--)
        {
            if (a[e] <= s)
                break;
            ans += a[e] - s;
        }
        cout << ans;
    }
}