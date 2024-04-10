#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXF = 2000000;
const int MAXN = 100001;

bool f[MAXF];
int a[MAXN];
int n, m;

int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    int k = 0;

    for (int i = 2; i < MAXF; i++)
        if (f[i] == false)
        {
            if (i >= MAXF / i) continue;
            for (int j = i * i; j < MAXF; j += i)
                f[j] = true;
        }

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d\n", &a[i]);
    sort(a, a + n);

    if (m > 2 && a[0] == 1)
    {
        puts("1");
        return 0;
    }

    int ans = 0;
    int i = 0;
    int x = 2;

    while (x < m)
    {
        ans++;

        while (i < n && a[i] < x) i++;
        if (i == n || a[i] != x)
        {
            puts("-1");
            return 0;
        }

        while (f[++x]);
    }

    printf("%d\n", ans);
    return 0;
}