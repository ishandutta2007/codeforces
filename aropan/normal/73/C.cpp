#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 111;
const int MAXK = 111;
const int INF = (int)1e+9;

char s[MAXN];
int c[26][26];

int f[MAXN][MAXK][26];
int n, m, k;


int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%s %d", s, &m);
    n = strlen(s);
    scanf("%d\n", &k);
    for (int i = 0; i < k; i++)
    {
        char x, y;
        int z;
        scanf("%c %c %d\n", &x, &y, &z);
        c[x - 'a'][y - 'a'] = z;
    }

    for (int i = 0; i < n; i++)
        s[i] -= 'a';

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int z = 0; z < 26; z++)
                f[i][j][z] = -INF;

    for (int i = 0; i < 26; i++)
        f[1][i != s[0]][i] = 0;

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= m; j++)
            for (int z = 0; z < 26; z++)
            {
                if (f[i][j][z] < -INF / 2) continue;
//                printf("%d %d %c = %d\n", i, j, z + 'a', f[i][j][z]);
                for (int x = 0; x < 26; x++)
                    f[i + 1][j + (s[i] != x)][x] = max(f[i + 1][j + (s[i] != x)][x], f[i][j][z] + c[z][x]);
            }
    int ans = -INF;
    for (int i = 0; i <= m; i++)
        for (int x = 0; x < 26; x++)
            ans = max(ans, f[n][i][x]);
    printf("%d\n", ans);
    return 0;
}