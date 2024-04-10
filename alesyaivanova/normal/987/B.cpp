#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (x <= 5 && y <= 5)
    {
        int x1 = 1;
        int y1 = 1;
        for (int i = 0; i < y; i++)
            x1 *= x;
        for (int i = 0; i < x; i++)
            y1 *= y;
        if (x1 > y1)
            cout << ">";
        else if (x1 == y1)
            cout << "=";
        else
            cout << "<";
    }
    else if (x == 1)
        cout << "<";
    else if (y == 1)
        cout << ">";
    else if (x > y)
        cout << "<";
    else if (x == y)
        cout << "=";
    else
        cout << ">";
}