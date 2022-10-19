#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m;
int** a;

int q[N];

int main()
{
    scanf("%d%d", &n, &m);
    a = new int*[n + 5];
    for (int i = 0; i < n; ++i)
    {
        a[i] = new int[m + 5];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
            q[i] = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((a[i][j] - (j + 1)) % m == 0)
            {
                int x = (a[i][j] - (j + 1)) / m;
                if (0 <= x && x < n)
                {
                    q[(i - x + n) % n]++;
                }
            }
        }
        int minu = n;
        for (int i = 0; i < n; ++i)
        {
            minu = min(minu, i + n - q[i]);
        }
        ans += minu;
    }
    printf("%d\n", ans);
    return 0;
}