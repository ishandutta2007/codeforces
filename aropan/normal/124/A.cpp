#include <cstdio>
#include <algorithm>

using namespace std;

int n, a, b;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", n - max(a + 1, n - b) + 1);
    return 0;
}