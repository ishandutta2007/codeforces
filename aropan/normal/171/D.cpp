#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    int ans[5] = {2, 3, 1, 2, 1};
    int n;
    scanf("%d", &n);
    n--;


    int t = clock();

    printf("%d\n", ans[n]);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}