#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXM = 100000;

int a, b, m, r;
int p[MAXM];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d %d %d", &a, &b, &m, &r);
    int i;
    for (i = 1; p[r] == 0; i++)
    {
        p[r] = i;
        r = (a * r + b) % m;
    }
    printf("%d\n", i - p[r]);
                         
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}