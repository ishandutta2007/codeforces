#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 111;

int n, m, ans;
int a[MAXN];

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);
    for (int i = 0; i < m && a[i] < 0; i++)
        ans -= a[i];

    printf("%d\n", ans);
    return 0;
}