#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;
    bool have1 = false;

    int n;
    cin >> n;

    while (n --) {
        int x, y;
        cin >> x >> y;

        x %= 2;
        y %= 2;

        a ^= x;
        b ^= y;

        if (x != y)
            have1 = true;
    }

    if (a != b) {
        cout << "-1\n";
    }
    else if (a == 0)
        cout << "0\n";
    else if (!have1)
        cout << "-1\n";
    else
        cout << "1\n";

    return 0;
}