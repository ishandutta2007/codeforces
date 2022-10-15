#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d", &n, &m);

    if (n > m) swap(n, m);

    if (m % (n - 1) == 1)
    {
        printf("%d\n", n);
        return 0;
    }

    int l, r, x;
    l = 0; r = 0;

    x = 0;
    do
    {
        l++;
        swap(l, r);
        x = (x + m - 1) % (n - 1);
    } while (x != 0);
    l++;

    int k;
    k = 0;
    x = 1;
    do
    {
        k++;
        x = (x + 2 * (m - 1)) % (2 * (n - 1));
    } while (x != 1);

    printf("%d\n", 2 + (n - l - r) / k);
    return 0;
}