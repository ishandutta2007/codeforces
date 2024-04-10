#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N], b[N];

bool stg()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == b[i])
            continue;
        if (a[i] - b[i] > 0)
            return false;
        int k = n + 1;
        for (int j = i; j <= n; ++j)
        {
            if (a[j] == b[j])
            {
                k = j;
                break;
            }
            if (a[j] - b[j] != a[i] - b[i])
                return false;
        }
        for (int j = k; j <= n; ++j)
        {
            if (a[j] != b[j])
                return false;
        }
        return true;
    }
    return true;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (stg())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}