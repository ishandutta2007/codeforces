#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = x; y <= n; y++) {
            int z = x ^ y;
            if ((x + y > z) && (y + z > x) && (x + z > y) && z >= y && z <= n) s++;
        }
    }
    cout << s;
    return 0;
}