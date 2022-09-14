#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

void swaprgb(long long *x, long long *y)
{
    long long k;
    k = *x;
    *x = *y;
    *y = k;
}

int main()
{
    long long r, g, b, s, ans;
    cin >> r >> g >> b;
    if (r > g)
        swaprgb(&r, &g);
    if (g > b)
        swaprgb(&g, &b);
    if (r > g)
        swaprgb(&r, &g);
    ans = 0;
    if (r + g > b / 2)
        ans = (r + g + b) / 3;
    else
        ans = (r + g);
    cout << ans;
}