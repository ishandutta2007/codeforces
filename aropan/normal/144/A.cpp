#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 107;

int a[MAXN];
int n, low, high;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    low = *min_element(a, a + n);
    high = *max_element(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == high)
        {
            for (int j = i - 1; j >= 0; j--)
                swap(a[j], a[j + 1]);
            ans += i;
            break;
        }

    for (int i = 0; i < n; i++)
        if (a[n - i - 1] == low)
        {
            ans += i;
            break;
        }
    printf("%d\n", ans);
    return 0;
}