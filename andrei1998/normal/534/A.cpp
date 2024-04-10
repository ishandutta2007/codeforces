#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    if (n == 1) {
        cout << "1\n1\n";
        return 0;
    }

    if (n == 2) {
        cout << "1\n1\n";
        return 0;
    }

    if (n == 3) {
        cout << "2\n1 3\n";
        return 0;
    }

    cout << n << '\n';
    for (int i = 2; i <= n; i += 2)
        cout << i << ' ';
    for (int i = 1; i <= n; i += 2)
        cout << i << ' ';
    cout << '\n';

    return 0;
}