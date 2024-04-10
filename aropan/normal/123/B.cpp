#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int a, b, x1, y1, x2, y2;
int x, y;



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    x = x1; y = y1;
    x1 = x + y;
    y1 = y - x;

    x = x2; y = y2;
    x2 = x + y;
    y2 = y - x; 

    a *= 2;
    b *= 2;

    x1 = x1 / a + (x1 > 0);
    x2 = x2 / a + (x2 > 0);
    y1 = y1 / b + (y1 > 0);
    y2 = y2 / b + (y2 > 0);

    cout << max(abs(y2 - y1), abs(x2 - x1)) << endl;
    return 0;
}