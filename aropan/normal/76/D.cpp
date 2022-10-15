#include <cstdio>
#include <iostream>

using namespace std;

unsigned long long a, b, x, y;

int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    cin >> a >> b;
    if (a < b)
    {
        cout << "-1" << endl;
        return 0;
    }

    x = a - b;

    if (x & 1)
    {
        cout << "-1" << endl;
        return 0;
    }

    x >>= 1;
    y = a - x;

    if (x > y) swap(x, y);

    if (x ^ y == b)
        cout << x << " " << y << endl;
    else
        cout << "-1" << endl;
    return 0;
}