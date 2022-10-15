#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int n;
char s[MAXN];
int c[256];
bool f[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
        c[s[i]]++;

    int k = 0;
    for (int i = 0; i < 256; i++)
        if (c[i] > c[k]) k = i;


    memset(f, true, sizeof(f));
    for (int i = 2; i * i <= n; i++)
        if (f[i])
            for (int j = i * i; j <= n; j += i)
                f[j] = false;

    f[1] = true;
    for (int i = 2; i + i <= n; i++)
        f[i] = false;

    for (int i = 1; i <= n; i++)
        if (!f[i])
        {
            if (c[k] == 0)
            {
                puts("NO");
                return 0;
            }
            c[s[i - 1] = k]--;
        }

    k = 0;
    for (int i = 1; i <= n; i++)
        if (f[i])
        {
            while (c[k] == 0) k++;
            c[s[i - 1] = k]--;
        }
    puts("YES");
    puts(s);
    return 0;
}