#include <iostream>

using namespace std;

int main()
{
    int l, r, a;
    cin >> l >> r >> a;
    int m = -1;
    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= r; j++) {
            for (int x = 0; x <= a; x++) {
                for (int y = 0; y <= a - x; y++) {
                    if (i + x == y + j) {
                        if (2 * (i + x) > m) m = 2 * (i + x);
                    }
                }
            }
        }
    }
    cout << m;
    return 0;
}