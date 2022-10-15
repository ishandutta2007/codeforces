#include <cstdio>
#include <algorithm>

using namespace std;

#define I first
#define J second

const int MAXN = 222222;
const int INF = (int)1e+9;

int a[MAXN];
int b[MAXN];
int d[MAXN];
int c[MAXN];
int f[MAXN][2];
pair <int, int> x[MAXN];
int n, m, k;

int F(int i, int j)
{
    int l = abs(a[i] - b[j]);
    if (l < d[j]) return c[j];
    if (l > d[j]) return 1;
    return 0;
}

int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &k, &k);

    if (m == 0)
    {
        printf("%d\n", n);
        return 0;
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    sort(a, a + n);
    sort(b, b + m);

    k = 0;
    for (int i = 0; i < m; i++)
        d[i] = INF;

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j + 1 < m && abs(a[i] - b[j]) > abs(a[i] - b[j + 1])) j++;

        if (j + 1 < m && abs(a[i] - b[j]) == abs(a[i] - b[j + 1]))
            x[++k] = make_pair(i, j);
        else
        {
            c[j] = c[j] * (d[j] <= abs(a[i] - b[j]));
            d[j] = min(d[j], abs(a[i] - b[j]));
            c[j] += d[j] == abs(a[i] - b[j]);
        }
    }

    if (k)
    {
        x[0].I = INF;
        x[0].J = INF;

        for (int i = 1; i <= k; i++)
        {
//            printf("%d %d\n", f[i - 1][0], f[i - 1][1]);
            fflush(stdout);
            if (x[i - 1].J + 1 != x[i].J)
            {
                if (1 < i)
                    f[i - 1][1] += F(x[i - 1].I, x[i - 1].J + 1);

                f[i][0] = min(f[i - 1][0], f[i - 1][1]) + F(x[i].I, x[i].J);
                f[i][1] = min(f[i - 1][0], f[i - 1][1]);
            }
            else
            {
                int
                    l = min(abs(a[x[i - 1].I] - b[x[i].J]), abs(a[x[i].I] - b[x[i].J])),
                    h = abs(a[x[i - 1].I] - b[x[i].J]) != abs(a[x[i].I] - b[x[i].J]),
                    add;

                if (l < d[x[i].J]) add = c[x[i].J] + h; else
                if (l == d[x[i].J]) add = h; else
                add = 2;


                f[i][0] = min(
                    f[i - 1][0] + F(x[i].I, x[i].J),
                    f[i - 1][1] + add
                );

                f[i][1] = min(f[i - 1][0], f[i - 1][1] + F(x[i - 1].I, x[i].J));
            }

        }
        f[k][1] += F(x[k].I, x[k].J + 1);
//        printf("%d %d\n", f[k][0], f[k][1]);
//        fflush(stdout);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
        ans += c[i];

    ans = n - k - ans;
    ans += min(f[k][0], f[k][1]);

    printf("%d\n", ans);

    return 0;
}