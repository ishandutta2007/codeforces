#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        if (x == y)
            cout << 2 * y << '\n';
        else
            cout << 2 * y - 1 << '\n';
    }
}