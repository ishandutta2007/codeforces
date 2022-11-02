#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int p, y;
    cin >> p >> y;
    while (y > p)
    {
        int mi = 0;
        for (int i = 2; i <= (int) sqrt(y) + 1; i++)
        {
            if (y % i == 0)
            {
                mi = i;
                break;
            }
        }
        if (mi && mi <= p)
            y--;
        else
            break;
    }
    if (y == p)
        cout << -1;
    else
        cout << y;
}