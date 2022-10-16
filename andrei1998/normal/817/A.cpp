#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x, y;
    cin >> x >> y;

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    if (dx % x != 0) {
        cout << "NO\n";
        return 0;
    }
    else if (dy % y != 0) {
        cout << "NO\n";
        return 0;
    }

    dx /= x;
    dy /= y;

    if (dx % 2 == dy % 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}