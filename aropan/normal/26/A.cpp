#include <cstdio>

using namespace std;

int n, ans;

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d", &n);
    for (int i = 4; i <= n; i++)
    {
        int x, k;
        x = i;
        k = 0;
        for (int j = 2; j * j <= x; j++)
            if (x % j == 0)
            {
                k++;
                do x /= j; while (x % j == 0);
            }
        ans += (k + (x != 1)) == 2;
    }
    printf("%d\n", ans);
    return 0;
}