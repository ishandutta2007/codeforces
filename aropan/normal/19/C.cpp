#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

const int MAXN = 222222;
const int MAXM = 22;


map <int, int> last;
int next[MAXN];
int a[MAXN];
int f[MAXN][MAXM], l[MAXN][MAXM];
int k[MAXN];
int n, m, x;

pair <int, int> d[MAXN];

int main()
{
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &n);
    m = 0;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);

        next[i] = last[a[i]];
        last[a[i]] = i;

        int x = next[i];

        while (x)
        {
            f[i][k[i]] = i - x;
            l[i][k[i]] = 1;

            k[i]++;

            x = next[x];
        }

        for (int j = 0; j < k[i]; j++)
            for (int z = 0; z < k[i - 1]; z++)
                if (f[i][j] == f[i - 1][z])
                {
                    l[i][j] = l[i - 1][z] + 1;
                    break;
                }
/*
        for (int j = 0; j < k[i]; j++)
            printf("%d-%d, ", f[i][j], l[i][j]);
        printf("\n");
*/
        for (int j = 0; j < k[i]; j++)
            if (l[i][j] >= f[i][j])
            {
                d[m].first = f[i][j];
                d[m].second = i - f[i][j];
                m++;
                break;
            }
    }
    sort(d, d + m);

    x = 1;
    for (int i = 0; i < m; i++)
        if (x <= d[i].second - d[i].first + 1)
            x = d[i].second + 1;

    printf("%d\n", n - x + 1);
    for (int i = x; i <= n; i++)
    {
        if (x < i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}