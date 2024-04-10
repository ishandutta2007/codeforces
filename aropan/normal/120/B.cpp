#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXN = 1001;

int n, x;
int a[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    x--;

    while (!a[x]) (x += 1) %= n;
    printf("%d\n", x + 1);

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}