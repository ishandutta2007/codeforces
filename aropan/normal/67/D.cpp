#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000001;

int a[MAXN], f[MAXN];
int n;


int modify(int x, int v)
{
    for (int i = x; 1 <= i; i -= i & -i)
        f[i] = max(f[i], v);
    return 0;
}

int find(int x)
{
    int res = 0;
    for (int i = x; i <= n; i += i & -i)
        res = max(res, f[i]);
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        modify(a[x], find(a[x]) + 1);
    }
    printf("%d\n", find(1));
    return 0;
}