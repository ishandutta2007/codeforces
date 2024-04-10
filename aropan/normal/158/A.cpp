#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXN = 55;

int n, m;
int a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int x = 0;
    while (x < n && a[x] && a[m - 1] <= a[x]) x++;
    printf("%d\n", x);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}