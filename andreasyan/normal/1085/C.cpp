#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int x[3], y[3];

void pr(int x, int y, int fx, int fy)
{
    while (x < fx)
    {
        ++x;
        printf("%d %d\n", x, y);
    }
    while (x > fx)
    {
        --x;
        printf("%d %d\n", x, y);
    }
    while (y < fy)
    {
        ++y;
        printf("%d %d\n", x, y);
    }
    while (y > fy)
    {
        --y;
        printf("%d %d\n", x, y);
    }
}

int main()
{
    for (int i = 0; i < 3; ++i)
        scanf("%d%d", &x[i], &y[i]);
    int ans = N * N;
    int ansx, ansy;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int yans = 0;
            for (int k = 0; k < 3; ++k)
                yans += (abs(i - x[k]) + abs(j - y[k]) + 1);
            yans -= 2;
            if (yans < ans)
            {
                ans = yans;
                ansx = i;
                ansy = j;
            }
        }
    }
    printf("%d\n", ans);
    printf("%d %d\n", ansx, ansy);
    for (int i = 0; i < 3; ++i)
        pr(ansx, ansy, x[i], y[i]);
    return 0;
}