#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n, ans, nok, cur, temp, er, x, y, a, b, x1, y1;
    cin >> x >> y >> a >> b;
    x1 = x;
    y1 = y;
    while (y > 0)
    {
        temp = x % y;
        x = y;
        y = temp;
    }
    nok = x1 / (y + x) * y1;
    cur = a;
    while (cur % nok != 0)
        cur++;
    if (cur > b)
        cout << 0;
    else
        cout << (b - cur) / nok + 1;
    return 0;
}