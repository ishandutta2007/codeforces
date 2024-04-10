#include <iostream>

using namespace std;

int main()
{
    int x, k1, k2;
    cin >> x;
    k1 = x / 36;
    x = x % 36;
    k2 = (x + 1) / 3;
    if (k2 == 12)
    {
        k1++;
        k2 = 0;
    }
    cout << k1 << " " << k2;
    return 0;
}