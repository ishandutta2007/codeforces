#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

int p[N], s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] | a[i]);
    for (int i = n; i >= 1; --i)
        s[i] = (s[i + 1] | a[i]);
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxu = max(maxu, ((p[n]) - (p[i - 1] | s[i + 1])));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (maxu == ((p[n]) - (p[i - 1] | s[i + 1])))
        {
            printf("%d ", a[i]);
            for (int j = 1; j <= n; ++j)
            {
                if (j == i)
                    continue;
                printf("%d ", a[j]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}