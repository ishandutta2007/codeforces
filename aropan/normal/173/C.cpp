#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int INF = (int)1e+9;

const int
    dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, 1, 0, -1};

const int MAXN = 505;

int s[MAXN][MAXN];
int a[MAXN][MAXN];
int n, m;
int ans;

int sum(int x1, int y1, int x2, int y2)
{
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (x1 < 1 || y1 < 1 || n < x2 || m < y2) return -INF;
    x1--;
    y1--;
    return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
//    printf("%d\n", sum(3, 3, 6, 5));

    ans = -INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int d = 1; d < 4; d += 2)
            {
                int x = i, y = j, l = 2, k = d, iter = 0;
                int s = a[x][y];
                do
                {
                    int s1 = sum(x + dx[k], y + dy[k], x + 2 * dx[k], y + 2 * dy[k]);
                    x += 2 * dx[k];
                    y += 2 * dy[k];
                    k = k == 0? 3 : k - 1;

                    int s2 = sum(x + dx[k], y + dy[k], x + l * dx[k], y + l * dy[k]);
                    x += l * dx[k];
                    y += l * dy[k];
                    k = k == 0? 3 : k - 1;

                    int s3 = sum(x + dx[k], y + dy[k], x + l * dx[k], y + l * dy[k]);
                    x += l * dx[k];
                    y += l * dy[k];
                    if (s1 == -INF || s2 == -INF || s3 == -INF) break;
                    s += s1 + s2 + s3;
                    l += 2;
                    iter++;
                    if ((iter & 1) ^ (d / 2))
                    {
                        ans = max(s, ans);
//                        printf("%d %d %d, %d %d %d, %d\n", i, j, d, x, y, k, s);
                    }
                } while (true);
            }
    printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}