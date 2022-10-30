#include <cstdio>

int t, sx, sy, fx, fy;

int main()
{
    //freopen("B.in", "r", stdin);
    scanf("%d %d %d %d %d\n", &t, &sx, &sy, &fx, &fy);
    long long dx = (long long)fx-sx;
    long long dy = (long long)fy-sy;
    for (int i = 0; i < t; i++)
    {
        char c;
        scanf("%c\n", &c);
        if (c == 'E')
        {
            if (dx > 0)
            {
                dx--;
            }
        }
        else if(c == 'W')
        {
            if (dx < 0)
            {
                dx++;
            }
        }
        else if(c == 'N')
        {
            if (dy > 0)
            {
                dy--;
            }
        }
        else
        {
            if (dy < 0)
            {
                dy++;
            }
        }
        if (dx == 0 && dy == 0)
        {
            printf("%d", i+1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}