#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


const int MAXN = 155;


int n, m;
char a[MAXN][MAXN];
int l[MAXN], r[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        gets(a[i] + 1);

    for (int i = 1; i <= n; i++)
    {
        l[i] = 1;
        while (l[i] <= m && a[i][l[i]] == 'G') l[i]++;
        r[i] = m;
        while (1 <= r[i] && a[i][r[i]] == 'G') r[i]--;
    }
    while (n && r[n] == 0) n--;

    if (n == 0)
    {
        puts("0");
        return 0;
    }

    l[n + 1] = m + 1;
    r[n + 1] = 0;

    int ans = 0;
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        int y;
        if (i & 1)
            y = max(max(r[i], r[i + 1]), x);
        else
            y = min(min(l[i], l[i + 1]), x);
        ans += abs(y - x);
        x = y;
    }
    printf("%d\n", ans + n - 1);
    return 0;
}