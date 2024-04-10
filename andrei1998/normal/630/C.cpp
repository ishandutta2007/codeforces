#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    cout << (1ll << (x + 1)) - 2 << endl;
    return 0;
}