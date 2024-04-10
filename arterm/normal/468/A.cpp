#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    int n;

    cin >> n;

    if (n <= 3) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    if (n % 2 == 0) {
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        for (int i = 5; i < n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
        return 0;
    }

    cout << "5 + 1 = 6\n";
    cout << "6 * 4 = 24\n";
    cout << "3 - 2 = 1\n";
    cout << "24 * 1 = 24\n";
    for (int i = 6; i < n; i += 2) {
        cout << i + 1 << " - " << i << " = 1\n";
        cout << "24 * 1 = 24\n";
    }

    return 0;
}