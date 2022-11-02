#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, h;
    cin >> n >> h;
    long long k;
    long long ans = 0;
    if (h >= 2000000000)
        k = n + 1;
    else
        k = (h - 1) * h / 2;
    if (k <= n)
    {
        n -= k;
        ans += h - 1;
    }
    else
    {
        long long left = 1;
        long long right = min(2000000000ll, h - 1);
        while (right - left > 1)
        {
            long long m = (left + right) / 2;
            if ((m + 1) * m <= 2 * n)
                left = m;
            else
                right = m;
        }
        if ((left + 1) * left == 2 * n)
            cout << left;
        else
            cout << left + 1;
        return 0;
    }
    long long left = h - 1;
    if (n >= 2 * h)
    {
        left = h;
        long long right = 2000000000;
        while (right - left > 1)
        {
            long long m = (right + left) / 2;
            if ((m + h) * (m - h + 1) <= n)
                left = m;
            else
                right = m;
        }
        n -= (left + h) * (left - h + 1);
        ans += (left - h + 1) * 2;
    }
    if (n > 0)
    {
        if (n <= left + 1)
            ans++;
        else
            ans += 2;
    }
    cout << ans;
}