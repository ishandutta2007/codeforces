#include <cstdio>
#include <cstring>

using namespace std;

const int MAXL = 55;
const int MAXM = 222;

int n, m, d;
int x, y;
bool f[MAXM][MAXL];
char s[MAXL];
char c[MAXL];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d %d\n", &n, &x, &y);
    gets(c);
    if (strcmp(c, "to head") == 0)
        d = -1;
    else
        d = 1;

    scanf("%s", s + 1);
    m = strlen(s + 1);
    s[0] = '0';

    f[1][x] = true;
    for (int i = 1; i <= m; i++)
    {
        bool flag = false;
        for (int j = 1; j <= n; j++)
            flag |= f[i][j];

        if (!flag)
        {
            printf("Controller %d\n", i - 1);
            return 0;
        }

        y += d;
        if (s[i] == '1')
        {
            for (int j = 1; j <= n; j++)
                f[i + 1][j] = true;
            f[i + 1][y] = false;
        }
        else
        {
            for (int j = 1; j <= n; j++)
                f[i + 1][j] = f[i][j - 1] || f[i][j + 1] || f[i][j];
            f[i + 1][y - d] = f[i + 1][y] = false;
        }
        if (y == 1 || y == n) d = -d; 
    }

    printf("Stowaway\n");
    return 0;
}