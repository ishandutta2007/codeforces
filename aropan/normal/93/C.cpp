#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

pair < pair <int, int>, int > c[MAXN];
pair < pair <int, int>, int > ans[MAXN];

int a[MAXN];
int n, t;

int rec(int m)
{
    if (m >= t) return 0;
    for (int j = -1; j < m; j++)
        for (int i = 0; i < m; i++)
            for (int k = 0; k < 4; k++)
            {
                a[m] = ((0 <= j)? a[j] : 0) + (1 << k) * a[i];
                c[m] = make_pair(make_pair(i, k), j);

                if (a[m] == n)
                {
                    t = m;
                    for (int i = 1; i <= m; i++)
                        ans[i] = c[i];
                    return 0;
                }

                if (n > a[m] && a[m] > a[m - 1])
                    rec(m + 1);
            }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d\n", &n);

    if (n == 1)
    {
        printf("0\n");
        return 0;
    }

    a[0] = 1;
    t = 8;
    rec(1);

    printf("%d\n", t);
    for (int i = 1; i <= t; i++)
    {
        if (ans[i].second == -1)
            printf("lea e%cx, [%d*e%cx]\n", i + 'a', 1 << ans[i].first.second, ans[i].first.first + 'a');
        else
            printf("lea e%cx, [e%cx + %d*e%cx]\n", i + 'a', ans[i].second + 'a', 1 << ans[i].first.second, ans[i].first.first + 'a');
    }
    return 0;
}