#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int x0, x1, a, b;
    cin >> x0 >> x1 >> a >> b;
    bool sw = false;
    if(x0 > x1) {
        swap(x0, x1);
        a *= -1;
        b *= -1;
        swap(a, b);
        sw = true;
    }
    if(b <= 0) {
        cout << "DRAW\n";
        return 0;
    }
    if(a <= 0) {
        if(x0 + a <= x1 && x1 <= x0 + b) {
            cout << "FIRST\n";
            if(sw)
                cout << x0 << '\n';
            else
                cout << x1 << '\n';
        }
        else
            cout << "DRAW\n";
        return 0;
    }
    int pos = (x1 - x0) % (a + b);
    if(!pos)
        cout << "SECOND\n";
    else if(a <= pos && pos <= b) {
        cout << "FIRST\n";
        if(sw)
            cout << x1 - pos << '\n';
        else
            cout << x0 + pos << '\n';
    }
    else
        cout << "DRAW\n";
    return 0;
}