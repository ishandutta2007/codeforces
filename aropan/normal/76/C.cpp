#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200002;
const int MAXK = 22;
const int MAXM = 1 << MAXK;

char s[MAXN];
int curr[MAXK];
int a[MAXK][MAXK], p[MAXK];
int f[MAXM];
int n, m, k, t, c;

int opr_sort(const int &i, const int &j)
{
    return curr[i] > curr[j];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d %d\n", &n, &k, &t);
    scanf("%s", s + 1);

    for (int i = 0; i < k; i++)
        scanf("%d", &f[1 << i]);
          
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < k; i++)
        p[i] = i;

    for (int i = 1; i <= n; i++)
    {
        s[i] -= 'A';
        c |= 1 << s[i];
        int m = 0;

        sort(p, p + k, opr_sort);
        for (int j = 0; j < k; j++)
        {
            if (curr[p[j]] == 0) break;

            f[m] += a[p[j]][s[i]];
            f[m | (1 << p[j])] -= a[p[j]][s[i]];
            f[m | (1 << s[i])] -= a[p[j]][s[i]];
            f[m | (1 << p[j]) | (1 << s[i])] += a[p[j]][s[i]];
            m |= 1 << p[j];
        }
        curr[s[i]] = i;
    }

    for (int i = 0; i < k; i++)
        for (int j = 0; j < (1 << k); j++)
            if ((1 << i) & j)
                f[j] += f[j ^ (1 << i)];

    int ans = 0;
    for (int i = 0; i < (1 << k) - 1; i++)
        ans += f[i] <= t && (i & c) == i && i != c;

    printf("%d\n", ans);
    return 0;
}