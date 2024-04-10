#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXL = 10007;

char s[MAXL];
int n, m;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    gets(s);
    n = strlen(s);
    m = 0;
    for (int i = 0; i < n; i++)
        if ((m && s[m - 1] != ' ') || s[i] != ' ') s[m++] = s[i];
    s[n = m] = 0;

    for (int i = 1; i < n; i++)
        if (s[i - 1] == ' ' && (s[i] == ',' || s[i] == '!' || s[i] == '?' || s[i] == '.'))
            swap(s[i - 1], s[i]);

    m = 0;
    for (int i = 0; i < n; i++)
        if ((m && s[m - 1] != ' ') || s[i] != ' ') s[m++] = s[i];
    s[n = m] = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%c", s[i]);
        if ((s[i] == ',' || s[i] == '!' || s[i] == '?' || s[i] == '.') && s[i + 1] != ' ')
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}