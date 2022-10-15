#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 107;

int n;
int a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    int fs, sc;
    fs = sc = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 710)
        {
            fs++;
            sc += max(a[i] - 350, 0);
        }
    }

    printf("%d %d\n", fs, sc);
    return 0;
}