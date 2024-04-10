#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;


const int MAXL = 127;


char s[MAXL];
int ans, k;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    gets(s);
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (k == 5 || i && s[i - 1] != s[i])
        {
            ans++;
            k = 0;
        }
        k++;
    }
    if (k) ans++;
    printf("%d\n", ans);
    return 0;
}