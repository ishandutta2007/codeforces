#include <cstdio>

using namespace std;

int x, y;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    while (scanf("%d %d", &x, &y) == 2)
    {

        do
        {
            if (2 <= x && 2 <= y)
            {
                x -= 2;
                y -= 2;
            }
            else
            if (1 <= x && 12 <= y)
            {
                x -= 1;
                y -= 12;
            }
            else
            if (0 <= x && 22 <= y)
            {
                x -= 0;
                y -= 22;
            }
            else
            {
                puts("Hanako");
                break;
            }

            if (0 <= x && 22 <= y)
            {
                x -= 0;
                y -= 22;
            }
            else
            if (1 <= x && 12 <= y)
            {
                x -= 1;
                y -= 12;
            }
            else
            if (2 <= x && 2 <= y)
            {
                x -= 2;
                y -= 2;
            }
            else
            {
                puts("Ciel");
                break;
            }
        } while (true);
    }
    return 0;
}