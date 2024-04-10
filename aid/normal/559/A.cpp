#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int a0, a1, a2, a3, a4, a5;
    cin >> a0 >> a1 >> a2 >> a3 >> a4 >> a5;
    cout << (a0 + a1) * (a1 + a2) - a1 * a1 +
        (a3 + a4) * (a4 + a5) - a4 * a4 << '\n';
    return 0;
}