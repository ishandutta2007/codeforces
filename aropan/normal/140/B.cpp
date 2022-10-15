#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 307;

int a[MAXN][MAXN];
int n, m, k;
pair <int, int> ans[MAXN];
pair <int, int> v[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            a[i][x] = j;
        }
        a[i][0] = n;
    }

    for (int i = 1; i <= n; i++)
        ans[i] = make_pair(0, 0);

    for (int i = 1; i <= n; i++)
    {
        v[m++] = make_pair(a[n + 1][i], i);
        sort(v, v + m);
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (j == v[k].second) continue;
                if (a[j][ans[j].first] > a[j][v[k].second])
                    ans[j] = make_pair(v[k].second, i);
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d", ans[i].second);
        if (i < n) printf(" ");
    }
    printf("\n");
    return 0;
}