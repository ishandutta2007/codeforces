#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;


const int MAXN = 1111;

char c[3][20] = {"Carrots", "Kiwis", "Grapes"};

int a[MAXN];
int n, m, k, q;
int x, y;
set <int> s;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d %d %d", &n, &m, &k, &q);

    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        a[i] = x * m + y;
    }
    sort(a, a + k);

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        x = x * m + y;
        int j = lower_bound(a, a + k, x) - a;

        if (a[j] == x)
            puts("Waste");
        else
            printf("%s\n", c[(x - j) % 3]);
    }
    return 0;
}