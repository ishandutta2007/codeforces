#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long x, y, m;
    cin >> x >> y >> m;
    if(x > y)
        swap(x, y);
    if(y <= 0 && y < m)
        cout << -1 << '\n';
    else {
        long long i = 0;
        while(true) {
            if(y >= m) {
                cout << i << '\n';
                return 0;
            }
            i += (y - x) / y + 1;
            x += ((y - x) / y + 1) * y;
            swap(x, y);
        }
    }
    return 0;
}