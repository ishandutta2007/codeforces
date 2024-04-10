#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;
int x, y;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    while (scanf("%d %d", &a, &b) == 2)
    {
        x = b / __gcd(a, b);
        y = a / __gcd(a, b);

        if (a < b)
            x--;
        else
            y--;

        
        if (x > y)
        {
            puts("Dasha");
        }
        else
        {
            if (x < y)
                puts("Masha");
            else
                puts("Equal");
        }
    }
    return 0;
}