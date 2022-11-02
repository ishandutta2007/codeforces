#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    if (k > 18 * 2)
    {
        cout << -1;
        return 0;
    }
    while (k > 1)
    {
        cout << 8;
        k -= 2;
    }
    if (k == 1)
        cout << 6;
}