#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x == 0)
    {
        if (y == 1)
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
    if (y == 1 || y == 0)
    {
        cout << "No";
        return 0;
    }
    x -= 1;
    y -= 2;
    if (y > x)
    {
        cout << "No";
        return 0;
    }
    if ((x - y) % 2 == 0)
        cout << "Yes";
    else
        cout << "No";
}