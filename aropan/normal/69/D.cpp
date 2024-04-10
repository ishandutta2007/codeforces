#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 201;
const int MAXM = (MAXN << 1) + 1;

int f[MAXM][MAXM];
int dx[MAXN], dy[MAXN];
int x, y, n, d;

int rec(int x, int y)
{
    if (x * x + y * y > d) return 1;
    int &res = f[x + MAXN][y + MAXN];

    if (res != -1) return res;

    res = 0;
    for (int i = 0; i < n; i++)
        if (!rec(x + dx[i], y + dy[i]))
        {
            res = 1;
            break;
        }
    return res;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d %d %d", &x, &y, &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &dx[i], &dy[i]);
    d *= d;
    memset(f, 0xff, sizeof(f));

    printf("%s\n", rec(x, y)? "Anton" : "Dasha");

            
    return 0;
}