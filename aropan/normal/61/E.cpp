#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000007;

int a[MAXN];
int A[MAXN];
long long f[2][MAXN];
int n, m;

int modify(int x, long long d, long long *f)
{
    while (x <= n)
    {
        f[x] += d;
        x = (x | (x - 1)) + 1;
    }
    return 0;
}

long long find(int x, long long *f)
{
    long long res = 0;
    while (x)
    {
        res += f[x];
        x = (x & (x - 1));
    }
    return res;
}

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        A[i] = a[i];
    }
    sort(A, A + n);
    m = unique(A, A + n) - A;

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(A, A + m, a[i]) - A + 1;


    long long ans = 0;
    for (int i = n; i--; )
    {
        modify(a[i], 1, f[0]);
        modify(a[i], find(a[i] - 1, f[0]), f[1]);

        ans += find(a[i - 1], f[1]);
    }
    printf("%I64d\n", ans);
    return 0;
}