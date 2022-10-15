#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXN = 55;

int n, m, A, B, C;
int x[MAXN][MAXN];

int sum(int x1, int y1, int x2, int y2)
{
    return x[x2][y2] - x[x1 - 1][y2] - x[x2][y1 - 1] + x[x1 - 1][y1 - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &x[i][j]);
            x[i][j] += x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1];
        }

    scanf("%d %d %d", &A, &B, &C);
    int ans = 0;

    if (A > B) swap(A, B);
    if (A > C) swap(A, C);
    if (B > C) swap(B, C);


    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int
                a = sum(1, 1, i, m),
                b = sum(i + 1, 1, j, m),
                c = sum(j + 1, 1, n, m);

            if (a > b) swap(a, b);
            if (a > c) swap(a, c);
            if (b > c) swap(b, c);


            ans += (A == a && B == b && C == c);
        }

    for (int i = 1; i < m; i++)
        for (int j = i + 1; j < m; j++)
        {
            int
                a = sum(1, 1, n, i),
                b = sum(1, i + 1, n, j),
                c = sum(1, j + 1, n, m);

            if (a > b) swap(a, b);
            if (a > c) swap(a, c);
            if (b > c) swap(b, c);


            ans += (A == a && B == b && C == c);
        }
    printf("%d\n", ans);
    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}