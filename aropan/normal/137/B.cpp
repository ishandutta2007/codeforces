#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

int a[MAXN];
int n, ans, x;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (1 <= x && x <= n && a[x] == 0)
        {
            a[x]++;
            ans++;
        }
    }
    printf("%d\n", n - ans);
    return 0;
}