#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    cout << max(abs(x1 - x0), abs(y1 - y0)) << '\n';
    return 0;
}