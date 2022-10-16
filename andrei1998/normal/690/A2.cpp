#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n & 1)
        cout << (n - 1) / 2 << '\n';
    else {
        int p = 1;
        while (2 * p <= n)
            p *= 2;
        n -= p;

        cout << (n / 2) << '\n';
    }
    return 0;
}