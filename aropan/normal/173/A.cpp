#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

#define FS first
#define SC second

using namespace std;

const int MAXX = 1007;

pair <int, int> f[MAXX][MAXX];
int upd[MAXX][MAXX];
char a[MAXX];
char b[MAXX];
int n, m, x, y, k;
int fs, sc;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d\n", &k);
    scanf("%s\n", a);
    scanf("%s\n", b);
    n = strlen(a);
    m = strlen(b);
    x = y = 0;
    fs = sc = 0;
    for (int i = 1; i <= k; )
    {
//*
        if (upd[x][y] && k - i + 1 >= i - upd[x][y])
        {
            int v = (k - i + 1) / (i - upd[x][y]);
            fs += v * (fs - f[x][y].FS);
            sc += v * (sc - f[x][y].SC);
            i += v * (i - upd[x][y]);
        }
        else
//*/
        {
            f[x][y] = make_pair(fs, sc);
            upd[x][y] = i;
            if (a[x] != b[y])
            {
                if (
                    a[x] == 'S' && b[y] == 'P' ||
                    a[x] == 'P' && b[y] == 'R' ||
                    a[x] == 'R' && b[y] == 'S'
                )
                    fs++;
                else
                    sc++;
            }
            x++;
            if (x == n) x = 0;
            y++;
            if (y == m) y = 0;
            i++;
        }
    }
    printf("%d %d\n", sc, fs);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}