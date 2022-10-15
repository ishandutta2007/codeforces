#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100001;

int n;
int a[MAXN], b[MAXN], d[MAXN];
int x[MAXN];
bool f[MAXN];

int run()
{
    for (int i = 1; i <= n; i++)
        x[i] = x[i - 1] + a[i] - b[i];

    int m = x[1];
    for (int i = 1; i <= n; i++)
        m = min(m, x[i]);

    for (int i = 1; i <= n; i++)
        f[d[i % n + 1]] |= (x[i] == m);

    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
        d[i] = i;

    run();

    reverse(a + 1, a + 1 + n);
    reverse(b + 1, b + 1 + n);
    b[n + 1] = b[1];
    memmove(b + 0, b + 1, sizeof(b[0]) * (n + 1));

    for (int i = 1; i <= n; i++)
        d[i] = n - i + 1;

    run();

    int k = 0;
    for (int i = 1; i <= n; i++)
        k += f[i];

    printf("%d\n", k);
    for (int i = 1; i <= n; i++)
        if (f[i])
            printf("%d ", i);
    printf("\n");
    return 0;
}