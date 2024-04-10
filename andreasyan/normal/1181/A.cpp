#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y, z;
    cin >> x >> y >> z;
    cout << (x + y) / z << ' ';
    if (x / z + y / z == (x + y) / z)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << z - max(x % z, y % z) << endl;
    return 0;
}