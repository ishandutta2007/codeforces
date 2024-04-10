#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int l = 0, r = 10 * 1000 * 1000;
    while(l < r - 1) {
        int m = (l + r) / 2, cnta = m / 2 - m / 6, cntb = m / 3 - m / 6,
            need = max(0, a - cnta) + max(0, b - cntb);
        if(need * 6 <= m)
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
    return 0;
}