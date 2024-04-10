#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 7003;

int n;
long long a[N];
int b[N];

int m;
int q[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((a[i] | a[j]) != a[j])
            {
                ++q[i];
            }
        }
    }
    m = n;
    while (1)
    {
        int maxu = -1;
        int x;
        for (int i = 1; i <= n; ++i)
        {
            if (q[i] > maxu)
            {
                maxu = q[i];
                x = i;
            }
        }
        if (maxu < 0)
            break;
        if (maxu == m - 1)
        {
            --m;
            q[x] = -1;
            for (int y = 1; y <= n; ++y)
            {
                if ((a[y] | a[x]) != a[x])
                    --q[y];
            }
        }
        else
            break;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] >= 0)
            ans += b[i];
    }
    cout << ans << endl;
    return 0;
}