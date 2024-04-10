#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int turn = 1;

    int who = 0;
    while (1) {
        if (who == 0) {
            if (a < turn) {
                cout << "Vladik" << '\n';
                return 0;
            }
            else
                a -= turn;
        }
        else {
            if (b < turn) {
                cout << "Valera" << '\n';
                return 0;
            }
            else
                b -= turn;
        }
        who ^= 1;
        ++ turn;
    }
    return 0;
}