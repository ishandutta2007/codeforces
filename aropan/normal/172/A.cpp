#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 100000;
const int MAXL = 22;

char s[MAXN], c[MAXN];
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    scanf("%s\n", s);
    m = strlen(s);

    for (int i = 1; i < n; i++)
    {
        scanf("%s\n", c);
        m = 0;
        while (s[m] == c[m]) m++;
        s[m] = 0;
    }
    printf("%d\n", m);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}