#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long double g[1010][1010];
long double d[1010][1010];
/*
long double rec(int w, int b, long double v, int h){
    if (w == 0)
        return 0;
    if (b == 0 && h == 1)
        return 1 * v;
    if (b == 0 && h == -1)
        return 0;
    if (h == 1){
        if (g[w][b] == -1)
            g[w][b] =(long double)w / (b + w) + rec(w, b - 1, (long double) b / (b + w), -1);
        return g[w][b] * v;
    }
    if (h == -1){
        if (d[w][b] == -1)
            d[w][b] = rec(w - 1, b - 1, (long double) b / (b + w) * w / (b + w - 1) , 1)
                                                + rec(w, b - 2, (long double) b / (b + w) * (b - 1) / (b + w - 1), 1);
        return d[w][b] * v;
    }
    return 0;
}
*/
long double rec(int w, int b, int h){
    if (w == 0)
        return 0;
    if (b == 0 && h == 1)
        return 1;
    if (b == 0 && h == -1)
        return 0;
    if (h == 1){
        if (g[w][b] == -1)
            g[w][b] =(long double)w / (b + w) + (long double) b / (b + w) * rec(w, b - 1, -1);
        return g[w][b];
    }
    if (h == -1){
        if (d[w][b] == -1)
            d[w][b] = (long double) b / (b + w) * w / (b + w - 1) * rec(w - 1, b - 1,  1)
                                                + (long double) b / (b + w) * (b - 1) / (b + w - 1) * rec(w, b - 2,  1);
        return d[w][b];
    }
    return 0;
}
int main()
{
    int w, b, i, j;
    long double ans;
    scanf("%d%d", &w, &b);
    for (i = 0; i <= w; i++)
        for (j = 0; j <= b; j++)
            g[i][j] = -1;
    for (i = 0; i <= w; i++)
        for (j = 0; j <= b; j++)
            d[i][j] = -1;
    ans = rec(w, b, 1);
    cout.precision(15);
    cout << fixed << ans;
    return 0;
}