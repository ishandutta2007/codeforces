#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100001;

int n;
int a[MAXN];
bool f[MAXN];

bool check(int m)
{
    if (m * 3 > n) return 0;

    for (int i = 0; i < m; i++)
        f[i] = true;

    for (int i = 0; i < n; i++)
        f[i % m] &= a[i];

    for (int i = 0; i < m; i++)
        if (f[i])
            return true;
    return false;
}

int main()
{
#ifdef ADEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        if (n % i == 0 && (check(i) || check(n / i)))
        {
            puts("YES");
            return 0;
        }
    puts("NO");
    return 0;
}