#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;


const int MAXN = 2002;

int c[MAXN][MAXN];
int a[MAXN][MAXN];
char s[MAXN][MAXN];
int n;
int ans = 0;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        gets(s[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = s[i][j] - '0';


    for (int iter = 0; iter < 2; iter++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= i; j--)
                a[i][j] ^= a[i - 1][j];

            int t = 0;

            for (int j = n; j > i; j--)
            {
                if ((t ^ a[i][j]) != c[i][j])
                {
                    t ^= 1;
                    a[i][j] ^= 1;
                    ans++;
                }
            }

            a[i][i] ^= t;
        }


        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
            {
                swap(a[i][j], a[j][i]);
                swap(c[i][j], c[j][i]);
            }
    
    }
    for (int i = 1; i <= n; i++)
        if (a[i][i] ^ c[i][i])
            ans++;

    printf("%d\n", ans);

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}