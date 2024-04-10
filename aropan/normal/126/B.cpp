#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXL = 1000007;

char s[MAXL];
int k[MAXL];
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    gets(s + 1);
    n = strlen(s + 1);


    for (int i = 2; i <= n; i++)
    {
        int x = k[i - 1];
        while (x && s[x + 1] != s[i]) x = k[x];
        x += s[x + 1] == s[i];
        k[i] = x;
    }


    int m = 0;
    for (int i = 2; i < n; i++)
        m = max(m, k[i]);

    int x = n;
    while (k[x] > m) x = k[x];
    m = k[x];


    if (m == 0)
    {
        puts("Just a legend");
        return 0;
    }

    s[m + 1] = 0;
    puts(s + 1);

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}