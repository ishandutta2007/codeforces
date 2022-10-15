#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define X first.first
#define Y first.second
#define T second

const int MAXN = 8;
const int MAXT = 1024;

char map[MAXN][MAXN];
int a[MAXN][MAXN][MAXT];
int n = 8;
int xs, ys, xf, yf;

queue < pair < pair <int, int>, int > > q;


int add(int x, int y, int t)
{
    if (x < 0 || n <= x || y < 0 || n <= y || t == MAXT || a[x][y][t]) return 0;
    int d = x - t + 1;
    if (0 <= d && map[d][y] == 'S') return 0;

    if (x == xf && y == yf)
    {
        puts("WIN");
        exit(0);
    }

    a[x][y][t] = 1;
    q.push(make_pair(make_pair(x, y), t));
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char ch;
            scanf("%c", &ch);
            map[i][j] = ch;

            switch (ch)
            {
                case 'A':
                    xf = i;
                    yf = j;
                break;
                case 'M':
                    xs = i;
                    ys = j;
                break;
                case 'S':
                break;
            }
        }
        scanf("\n");
    }


    q.push(make_pair(make_pair(xs, ys), 0));
    while (q.size())
    {
        int
            x = q.front().X,
            y = q.front().Y,
            t = q.front().T;
        q.pop();

        int d = x - t;
        if (0 <= d && map[d][y] == 'S') continue;

        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
                add(x + dx, y + dy, t + 1);
    }
    puts("LOSE");
    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}