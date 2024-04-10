#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long M = 998244353;
long long ast[30];

int n;
long long a[N];

int tq(long long x)
{
    int ans = 0;
    while (x)
    {
        ++ans;
        x /= 10;
    }
    return ans;
}

long long q[12];

long long ans;

void solv(long long y)
{
    for (long long i = 1; i <= 10; ++i)
    {
        long long x = y;
        int j = i;
        bool z = true;
        int k = 0;
        while (x)
        {
            if (z)
            {
                if (x == 0)
                    break;
                ans += (x % 10) * ast[k] * q[i];
                ans %= M;
                x /= 10;
                ++k;
            }
            else
            {
                if (j != 0)
                {
                    --j;
                    ++k;
                }
            }
            z ^= true;
        }
        x = y;
        j = i;
        z = false;
        k = 0;
        while (x)
        {
            if (z)
            {
                if (x == 0)
                    break;
                ans += (x % 10) * ast[k] * q[i];
                ans %= M;
                x /= 10;
                ++k;
            }
            else
            {
                if (j != 0)
                {
                    --j;
                    ++k;
                }
            }
            z ^= true;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        q[tq(a[i])]++;
    }
    ast[0] = 1;
    for (int i = 1; i < 30; ++i)
        ast[i] = (ast[i - 1] * 10) % M;
    for (int i = 1; i <= n; ++i)
    {
        solv(a[i]);
    }
    cout << ans << endl;
    return 0;
}