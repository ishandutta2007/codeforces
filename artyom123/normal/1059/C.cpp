#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n == 2) {
        cout << 1 << " " << 2;
        return 0;
    }
    if (n == 3) {
        cout << 1 << " " << 1 << " " << 3;
        return 0;
    }
    int c = 1;
    while (n > 0) {
        if (n == 1) {
            cout << c << " ";
            return 0;
        }
        if (n == 2) {
            cout << c << " " << 2 * c << "\n";
            return 0;
        }
        if (n == 3) {
            cout << c << " " << c << " " << 3 * c << "\n";
            return 0;
        }
        for (int i = 0; i < (n + 1) / 2; i++) {
            cout << c << " ";
        }
        n /= 2;
        c *= 2;
    }
    return 0;
}