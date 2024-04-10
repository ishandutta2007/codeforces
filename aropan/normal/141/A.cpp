#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 256;

int a[26];
char s[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    for (int i = 0; i < 3; i++)
    {
        gets(s);
        for (int j = 0, l = strlen(s); j < l; j++)
            a[s[j] - 'A'] += -1 + 2 * (i == 2);
    }

    for (int i = 0; i < 26; i++)
        if (a[i])
        {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}