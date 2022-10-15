#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;


const int MAXN = 1007;

const int
    dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, 1, 0, -1};

char a[MAXN][MAXN];
int f[MAXN][MAXN][4];
int n, m;

deque < pair < pair <int, int>, pair <int, int> > > D;

void add(int x, int y, int d, int l, bool flag)
{
    if (x < 0 || n + 1 < x || y < 0 || m + 1 < y || (f[x][y][d] && f[x][y][d] <= l)) return;
    f[x][y][d] = l;
    if (x < 1 || n < x || y < 1 || m < y) return;
    if (flag)
        D.push_front(make_pair(make_pair(-l, d), make_pair(x, y)));
    else
        D.push_back(make_pair(make_pair(-l, d), make_pair(x, y)));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s\n", a[i] + 1);

    add(1, 1, 1, 1, true);
    while (D.size())
    {
        int
            l = -D.front().first.first,
            d = D.front().first.second,
            x = D.front().second.first,
            y = D.front().second.second;
        D.pop_front();
        if (f[x][y][d] != l) continue;
//        printf("%d %d %d\n", x, y, d);
        add(x + dx[d], y + dy[d], d, l, true);

        if (a[x][y] == '#')
            for (int i = 0; i < 4; i++)
                add(x + dx[i], y + dy[i], i, l + 1, false);
    }
    printf("%d\n", f[n][m + 1][1] - 1);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}