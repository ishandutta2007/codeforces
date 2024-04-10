#include <bits/stdc++.h>
using namespace std;
const int N = 300005, M = 12;
const long long INF = 1000000009000000009;

int n;
long long m, k;
long long a[N];

long long p[N];

long long maxu[M][2];
int main()
{
    scanf("%d%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    long long ans = 0;
    for (int j = 0; j < m; ++j)
    {
        for (int z = 0; z < 2; ++z)
            maxu[j][z] = -INF;
    }
    maxu[0][0] = 0;
    maxu[0][1] = -k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (j < i % m)
            {
                if (maxu[j][1] != -INF)
                    ans = max(ans, p[i] - k * (i / m) + maxu[j][1]);
            }
            else
            {
                if (maxu[j][0] != -INF)
                    ans = max(ans, p[i] - k * (i / m) + maxu[j][0]);
            }
        }
        maxu[i % m][0] = max(maxu[i % m][0], -p[i] + k * (i / m));
        maxu[i % m][1] = max(maxu[i % m][1], -p[i] + k * (i / m) - k);
    }
    cout << ans << endl;
    return 0;
}