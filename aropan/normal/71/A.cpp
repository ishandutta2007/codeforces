#include <cstdio>
#include <cstring>

using namespace std;

char s[256];
int n, k;

int main()
{
#ifdef ADEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d\n", &k);
    while (k--)
    {
        scanf("%s", s);
        int l = strlen(s);
        if (l > 10)
            printf("%c%d%c\n", s[0], l - 2, s[l - 1]);
        else
            puts(s);
    }
    
    return 0;
}