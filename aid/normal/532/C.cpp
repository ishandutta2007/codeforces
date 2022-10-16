#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;
    if((xp <= xv && yp <= yv) || (xp + yp <= max(xv, yv)))
        cout << "Polycarp\n";
    else
        cout << "Vasiliy\n";
    return 0;
}