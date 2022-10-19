#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a <= (b - c))
    {
        cout << n / a << endl;
        return 0;
    }
    long long ans = 0;
    if (n >= b)
    {
        ans += (n - b) / (b - c) + 1;
        n -= ((n - b) / (b - c) + 1) * (b - c);
    }
    ans += (n / a);
    cout << ans << endl;
    return 0;
}