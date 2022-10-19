#include <bits/stdc++.h>
using namespace std;

long long n;

int main()
{
    cin >> n;
    long long ans = 0;
    while (1)
    {
        if (n % 2 == 0)
        {
            ans += (n / 2);
            break;
        }
        for (long long i = 3; i * i <= n ; ++i)
        {
            if (n % i == 0)
            {
                ++ans;
                n -= i;
                break;
            }
        }
        if (!ans)
        {
            ans++;
            n = 0;
        }
    }
    cout << ans << endl;
    return 0;
}