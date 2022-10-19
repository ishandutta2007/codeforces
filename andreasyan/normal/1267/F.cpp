#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m, ka, kb;
int a[N], b[N];

int q[N];

int main()
{
    scanf("%d%d%d%d", &n, &m, &ka, &kb);
    for (int i = 1; i <= ka; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= kb; ++i)
        scanf("%d", &b[i]);
    if (!(kb <= n - 1 && ka <= m - 1))
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    while (ka < m - 1)
    {
        a[++ka] = 1;
    }
    while (kb < n - 1)
    {
        b[++kb] = n + 1;
    }
    for (int i = 1; i <= n + m; ++i)
    {
        q[i] = 1;
    }
    for (int i = 1; i <= ka; ++i)
        q[a[i]]++;
    for (int i = 1; i <= kb; ++i)
        q[b[i]]++;
    set<int> sa, sb;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] == 1)
            sa.insert(i);
    }
    for (int i = n + 1; i <= n + m; ++i)
    {
        if (q[i] == 1)
            sb.insert(i);
    }
    int i = 1;
    int j = 1;
    for (int ii = 0; ii < n + m - 2; ++ii)
    {
        if (!sa.empty())
        {
            int x = *sa.begin();
            printf("%d %d\n", x, b[j]);
            --q[x];
            --q[b[j]];
            sa.erase(x);
            if (q[b[j]] == 1)
                sb.insert(b[j]);
            ++j;
        }
        else
        {
            int x = *sb.begin();
            printf("%d %d\n", x, a[i]);
            --q[x];
            --q[a[i]];
            sb.erase(x);
            if (q[a[i]] == 1)
                sa.insert(a[i]);
            ++i;
        }
    }
    int x;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] == 1)
            x = i;
    }
    int y;
    for (int i = n + 1; i <= n + m; ++i)
    {
        if (q[i] == 1)
            y = i;
    }
    printf("%d %d\n", x, y);
    return 0;
}