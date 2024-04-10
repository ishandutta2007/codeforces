#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 500000) x = 1000000 - x;
        else x--;
        if (m < x) m = x;
    }
    cout << m;
    return 0;
}