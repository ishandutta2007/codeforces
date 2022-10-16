#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int x = 0;
    cin >> x;

    int pushes = (n - x) % n;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (i & 1) {
            if ((x - pushes + n) % n != i) {
                cout << "NO\n";
                return 0;
            }
        }
        else {
            if ((x + pushes + n) % n != i) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}