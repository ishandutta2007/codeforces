#include <iostream>

using namespace std;

int main()
{
    int n, x = 0, y = 0, s = 0;
    bool b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'U') y++;
        else x++;
        if (i == 0) {
            if (x == 1) b = 1;
            else b = 0;
        }
        if (b == 1 && x < y) {
            s++;
            b = 0;
        }
        if (b == 0 && x > y) {
            b = 1;
            s++;
        }
    }
    cout << s;
    return 0;
}