#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int c = 2;
    int i = 1;
    while(c < n) {
        if ((a - 1) / c == (b - 1) / c) {
            cout << i;
            return 0;
        }
        c *= 2;
        i++;
    }
    if (c == n) cout << "Final!";
    return 0;
}