#include <cstdio>
#include <algorithm>

using namespace std;


const int MAXN = 100001;

int n, a[MAXN];

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

    if (a[n - 1] == 1)
        a[n - 1] = 2;
    else
        a[n - 1] = 1;
    sort(a, a + n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}