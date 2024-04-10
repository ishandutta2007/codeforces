#include <bits/stdc++.h>
using namespace std;

long long n, k, x, y;

int main()
{
    cin >> n >> k >> x >> y;
    long long ans = 0;
    if (k == 1)
    {
        cout << (n - 1) * x << endl;
        return 0;
    }
    while (1)
    {
        if (n == 1)
            break;
        if (n < k)
        {
            ans += (n - 1) * x;
            break;
        }
        if (n % k > 0)
        {
            ans += (n % k) * x;
            n -= (n % k);
        }
        long long m = n / k;
        ans += min((n - m) * x, y);
        n = m;
    }
    cout << ans << endl;
    return 0;
}