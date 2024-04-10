#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int v1, v2, v3, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    for (int b3 = max(v3, vm); 2 * vm >= b3 && 2 * v3 >= b3; b3++) {
        for (int b2 = max(b3 + 1, max(2 * vm + 1, v2)); b2 <= 2 * v2; b2++) {
            for (int b1 = max(b2 + 1, max(2 * vm + 1, v1)); b1 <= 2 * v1; b1++) {
                cout << b1 << endl << b2 << endl << b3;
                return 0;
            }
    }
    }
    cout << -1;

    return 0;
}