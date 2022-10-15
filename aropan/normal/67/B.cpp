#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int a[MAXN];
int c[MAXN];
int n, m, k;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);

    for (int i = 1; i <= n; i++)
        a[i] = n - i + 1;

    m = k;
    for (int i = k + 1; i <= n; i++)
    {
        int x = a[i];
        for (int j = i - 1; c[x]; j--)
        {
            c[x] -= a[j] >= x + k;
            swap(a[j], a[j + 1]);
        }
    }
    for (int i = n; i >= 1; i--)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}