#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 9 << " " << n - 9;
    } else if (n % 4 == 0) {
        cout << n / 2 << " " << n / 2;
    } else {
        cout << n / 2 - 1 << " " << n / 2 + 1;
    }

    return 0;
}