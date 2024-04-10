#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define L first
#define R second

const int MAXN = 200000;
const int MAXT = MAXN * 11;

char s[MAXN];
char c[MAXN];
int f[MAXN];
pair <int, int> a[MAXT];
int d[MAXN];
int n, m, k, t;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    gets(s + 1);
    n = strlen(s + 1);

    scanf("%d\n", &k);
    for (int I = 0; I < k; I++)
    {
        gets(c + 1);
        m = strlen(c + 1);
        c[m + 1] = 1;
        memmove(c + m + 2, s + 1, n + 1);
//        puts(c + 1);
        f[1] = 0;
        for (int i = 2, l = strlen(c + 1); i <= l; i++)
        {
            int &x = f[i];
            x = f[i - 1];
            while (x && c[x + 1] != c[i]) x = f[x];
            x += c[x + 1] == c[i];
            if (x == m)
            {
                int
                    l = i - m - m,
                    r = i - m - 1;

                a[t++] = make_pair(l, r);
            }
        }
    }

    sort(a, a + t);

    int r = n + 1;
    for (int i = 0; i < t; i++)
    {
        d[a[i].R]++;
        r = min(r, a[i].R);
    }

    int
        pos = 1,
        len = r - 1;

    for (int i = 0; i < t; i++)
    {
        d[a[i].R]--;
        while (r <= n && d[r] == 0) r++;
        int l = a[i].L;

//        printf("%d %d\n", l, r);

        if (r - l - 1 > len)
        {
            len = r - l - 1;
            pos = l + 1;
        }
    }

    printf("%d %d\n", len, pos - 1);
    return 0;
}