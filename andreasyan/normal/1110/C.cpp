#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int main()
{
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int n;
        cin >> n;

        /*int maxu = 0;
        for (int i = 1; i < n; ++i)
        {
            maxu = max(maxu, gcd(i ^ n, i & n));
        }
        cout << maxu << endl;*/

        bool z = false;
        for (int i = 0; i < 30; ++i)
        {
            if (n == ((1 << i) - 1))
            {
                z = true;
                break;
            }
        }
        if (z)
        {
            int ans = 0;
            for (int i = 1; i * i <= n; ++i)
            {
                if (n % i == 0)
                {
                    if (i != 1)
                        ans = max(ans, n / i);
                    ans = max(ans, i);
                }
            }
            cout << ans << endl;
        }
        else
        {
            for (int i = 0; i < 30; ++i)
            {
                if (n < ((1 << i) - 1))
                {
                    cout << ((1 << i) - 1) << endl;
                    break;
                }
            }
        }
    }
    return 0;
}