#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int ram;
    for (int i = 0; i <= c; ++ i) {
        ram = c - i * a;
        if (ram >= 0 && ram % b == 0) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}