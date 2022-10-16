#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int v = x / __gcd(x, y) * y;

    cout << b / v - (a - 1) / v << '\n';
    return 0;
}