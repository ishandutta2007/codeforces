#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 222;

int e[MAXN][MAXN];
int f[MAXN];
int a[MAXN];
int ans[MAXN];
int n, m, k;
queue <int> q;

int add(int x)
{
    if (!f[x]) return 0;
    f[x] = false;
    q.push(x);
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[j]);
            f[a[j]] = true;
        }

        for (int I = 0; I < m; I++)
            for (int J = I + 1; J < m; J++)
            {
                e[a[I]][a[J]]++;
                e[a[J]][a[I]]++;
            }
    }
    int m = 0;
    for (int i = 1; i < MAXN; i++)
        if (f[i])
            a[m++] = i;

    if (n == 2)
    {
        printf("%d", m - 1);
        for (int i = 1; i < m; i++)
            printf(" %d", a[i]);
        printf("\n");
        printf("1 %d\n", a[0]);
        return 0;
    }


    for (int i = 0; i < m; i++)
        if (f[a[i]])
        {
            while (q.size()) q.pop();
            add(a[i]);
            k = 0;
            while (q.size())
            {
                int x = q.front();
                q.pop();
                ans[k++] = x;
                for (int j = 0; j < m; j++)
                    if (e[x][a[j]] == n - 1)
                        add(a[j]);
            }
            printf("%d", k);
            for (int j = 0; j < k; j++)
                printf(" %d", ans[j]);
            printf("\n");
        }
    return 0;
}