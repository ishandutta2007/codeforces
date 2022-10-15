#include <cstdio>
#include <cmath>

#define abs(x) (x < 0? -x : x)

using namespace std;

int a, b, n;
int x;

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d %d %d", &a, &b, &n);
    for (int i = -1000; i <= 1000; i++)
    {
        int x = a;
        for (int j = 0; j < n && (i == 0 || abs(x) <= abs(b)); j++)
            x *= i;

        if (x == b)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("No solution");
    return 0;
}