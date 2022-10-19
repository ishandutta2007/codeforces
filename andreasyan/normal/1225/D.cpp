#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
int a[N];

int q[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        long long y = 1, z = 1;
        for (int j = 2; j * j <= x; ++j)
        {
            if (x % j == 0)
            {
                int q = 0;
                while (x % j == 0)
                {
                    x /= j;
                    ++q;
                }
                q %= k;
                for (int u = 0; u < q; ++u)
                    y *= j;
                q = (k - q) % k;
                for (int u = 0; u < q; ++u)
                {
                    if (z == -1)
                        break;
                    z *= j;
                    if (z > 100000)
                    {
                        z = -1;
                        break;
                    }
                }
            }
        }
        if (x > 1)
        {
            int j = x;
            int q = 0;
            while (x % j == 0)
            {
                x /= j;
                ++q;
            }
            q %= k;
            for (int u = 0; u < q; ++u)
                y *= j;
            q = (k - q) % k;
            for (int u = 0; u < q; ++u)
            {
                if (z == -1)
                    break;
                z *= j;
                if (z > 100000)
                {
                    z = -1;
                    break;
                }
            }
        }
        if (z != -1)
            ans += q[z];
        q[y]++;
    }
    cout << ans << endl;
    return 0;
}