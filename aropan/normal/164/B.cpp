#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 2000007;

int a[MAXN], b[MAXN];
int p[MAXN], q[MAXN];
int s[MAXN];
int f[MAXN];
int n, m, k;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        p[a[i]] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
        q[b[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        s[k++] = q[a[i]];

//    for (int i = 0; i < k; i++) printf("%d\n", s[i]);
    for (int i = 0; i < k; i++)
        s[i + k] = s[i];
    k += k;

    int ans = 0;
    for (int i = 0, j = 0, t = 0; i < k; i++)
    {
        if (j < i)
        {
            j = i;
            t = 0;
        }
        if (t < 0) t = 0;
        while (j < k && s[j] &&
            (
                (i == j) ||
                (t == 0) && 
                (
                    (s[j - 1] < s[j]) ||
                    (s[j - 1] > s[j] && s[j] < s[i])
                ) ||
                (t == 1) && 
                (
                    (s[j - 1] < s[j] && s[j] < s[i])
                )
            ))
        {
            if (i < j && s[j - 1] > s[j]) t++;
            j++;
        }
        ans = max(ans, j - i);

        if (s[i] > s[i + 1]) t--;
    }
    printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}