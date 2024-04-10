#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;


int a[5];
int n;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }

    int ans = 0;
    ans += a[4] + a[3];
    a[1] -= a[3];
    ans += (a[2] + 1) / 2;
    a[1] -= (a[2] % 2) * 2;
    ans += max(0, (a[1] + 3) / 4);
    printf("%d\n", ans);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}