#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define A first.second
#define B first.first
#define I second

const int MAXN = 300000;
const int MAXM = 300000;

int n, m, sqrtn;
int w[MAXN];
long long s[MAXN];
long long ans[MAXN];

pair < pair <int, int>, int > a[MAXM];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        a[i].I = i;
        scanf("%d %d", &a[i].A, &a[i].B);
    }
    sort(a, a + m);

    sqrtn = (int)sqrt(double(n));

    for (int i = 0, j = 0; i < m; i = j)
    {
        while (j < m && a[i].B == a[j].B) j++;

        if (a[i].B <= sqrtn)
        {
            for (int k = 1; k <= a[i].B; k++) s[n - k] = w[n - k];
            for (int k = n - a[i].B - 1; k >= 0; k--) s[k] = w[k] + s[k + a[i].B];
        }

        while (i < j)
        {
            if (a[i].B <= sqrtn)
            {
                ans[a[i].I] = s[a[i].A - 1];
            }
            else
            {
                long long *res = &ans[a[i].I];
                for (int k = a[i].A - 1; k < n; k += a[i].B)
                    *res += w[k];
            }
            i++;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%I64d\n", ans[i]);
    return 0;
}