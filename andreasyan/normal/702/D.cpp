#include <bits/stdc++.h>
using namespace std;

long long d, k, a, b, t;

int main()
{
    cin >> d >> k >> a >> b >> t;
    if (k >= d)
    {
        cout << a * d << endl;
        return 0;
    }
    long long pans = a * k;
    d -= k;
    long long ans = d * b;
    if (d % k == 0)
        ans = min(ans, d * a + (d / k) * t);
    else
        ans = min(ans, d * a + (d / k + 1) * t);
    if (d % k)
    {
        if (d > k)
            ans = min(ans, (d / k) * k * a + (d / k) * t + (d % k) * b);
    }
    cout << ans + pans << endl;
    return 0;
}