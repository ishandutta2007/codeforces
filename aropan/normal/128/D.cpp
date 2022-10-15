#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;


const int MAXN = 100007;

int n, m;
int a[MAXN];
int f[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int
        mi = *min_element(a, a + n),
        ma = *max_element(a, a + n);

    m = ma - mi;
    if (m > n + 1)
    {
        puts("NO");
        return 0;
    }


    for (int i = 0; i < n; i++)
        a[i] -= mi;

    for (int i = 0; i < n; i++)
        f[a[i]]++;

    for (int i = 0; i < m; i++)
    {
        f[i]--;
        if (f[i] < 0)
        {
            puts("NO");
            return 0;
        }
    }


    int x = 0;
    do
    {
        if (x > 0 && f[x - 1]) f[--x]--; else
        if (f[x + 1]) f[++x]--; else
            break;
    } while (true);

    for (int i = 0; i <= m; i++)
        if (f[i])
        {
            puts("NO");
            return 0;
        }
    puts(x == m? "YES" : "NO");

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}