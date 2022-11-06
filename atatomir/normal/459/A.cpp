#include <iostream>

using namespace std;

long x1,x2,y1,y2,d;

long abss(long x){
    if(x < 0) x = -x;
    return x;
}

int main()
{
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2){
         d = y2-y1;
         cout << x1 + d << ' ' << y1 << ' ' << x2+d << ' ' << y2;
    } else
    if(y1 == y2){
        d = x2-x1;
        cout << x1 << ' ' << y1+d << ' ' << x2 << ' ' << y2 + d;
    } else {
        if(abss(x2-x1) != abss(y2-y1)) {
            cout << -1 ;
            return 0;
        }
        if(x1 > x2){
            d = x1; x1 = x2; x2 = d;
            d = y1; y1 = y2; y2 = d;
        }
        d = x2-x1;
        cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
    }

    return 0;
}