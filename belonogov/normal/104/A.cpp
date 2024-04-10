#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n -= 10;
    if ((n >= 1 && n <= 9) or n == 11)
    {
        cout << 4;
        return 0;
    }
    if (n == 10)
    {
        cout << 15;
        return 0;
    }
    cout << 0;
    return 0;
}