#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100000;
const int INF = 1e+9;

int n, m;
int a[MAXN];
int f[MAXN];
char s[MAXN];

int main()
{
#ifdef ADEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d\n", &m);
    gets(s);

    n = 0;
    int l = strlen(s);
    for (int i = 0, j; i < l; i = j)
    {
        while (i < l && s[i] == ' ') i++;
        if (i == l) break;
        j = i;

        while (j < l && s[j] != '.' && s[j] != '?' && s[j] != '!') j++;
        j++;
        a[n++] = j - i;
    }


    for (int i = 0; i <= n; i++)
        f[i] = INF;

    f[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        for (int j = i; j < n; j++)
        {
            l += a[j] + 1;
            if (l - 1 > m) break;
            f[j + 1] = min(f[j + 1], f[i] + 1);
        }
    }

    if (f[n] == INF)
        puts("Impossible");
    else
        printf("%d\n", f[n]);

    return 0;
}

#ifdef ADEBUG
#endif