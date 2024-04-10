#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 10004, K = 22;

int n, k;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i)
        a[i] = 1;
    for (int i = 1; i <= k; ++i)
    {
        for (int i = 1; i <= n; ++i)
        {
            int l = 1, r = n;
            int ans;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (a[m] + a[i] <= (n - i))
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            printf("%d ", ans);
            b[i] = a[i] + a[ans];
        }
        printf("\n");
        for (int i = 1; i <= n; ++i)
            a[i] = b[i];
    }
    return 0;
}