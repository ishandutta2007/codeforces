#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int x1, x2, a, b, y, x, _x1, _x2;
    bool check = false;
    cin >> x1 >> x2 >> a >> b;
    _x1 = x1;
    _x2 = x2;
    if (x1 > x2){
        swap(x1, x2);
        a = -a;
        b = -b;
        swap(a, b);
        check = true;
    }
    x = x2 - x1;
    if (a < 1){
        if (x <= b){
            cout << "FIRST\n";
            cout << _x2;
        }
        else
            cout << "DRAW";
        return 0;
    }
    if (x % (a + b) == 0){
        cout << "SECOND";
        return 0;
    }
    y = (x / (a + b)) * (a + b);
    if (a <= x - y && x - y <= b){
        cout << "FIRST\n";
        if (check)
            cout << -(x - y) + _x1;
        else
            cout << (x - y) + _x1;
        return 0;
    }
    cout << "DRAW";


    return 0;
}