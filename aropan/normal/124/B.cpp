#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 8;
const int INF = (int)1e+9;

int a[MAXN][MAXN];
int n, k;
int p[MAXN];
int ans;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            char c;
            scanf("%c", &c);
            a[i][j] = c - '0';
        }
        scanf("\n");
    }

    for (int i = 0; i < k; i++)
        p[i] = i;

    ans = INF;
    do
    {
        int mi = INF, ma = -INF;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            for (int j = 0; j < k; j++)
                (x *= 10) += a[i][p[j]];
            ma = max(ma, x);
            mi = min(mi, x);
        }
        ans = min(ans, ma - mi);
    } while (next_permutation(p, p + k));
    printf("%d\n", ans);
    return 0;
}