#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
struct pnt{
    db x, y, r;
    pnt(){}
    pnt(db _x, db _y){
        x = _x;
        y = _y;
    }
    db len(){
        return x * x + y * y;
    }
    pnt operator - (const pnt & a) const{
        return pnt(x - a.x, y - a.y);
    }
};


int main(){
     pnt p1, p2;
    cin >> p1.x >> p1.y >> p1.r;
    cin >> p2.x >> p2.y >> p2.r;
    if (p1.r < p2.r)
        swap(p1, p2);
    cout.precision(15);
    if (sqrt((p1 - p2).len()) + p2.r < p1.r){
        cout << fixed << (p1.r - (sqrt((p1 - p2).len()) + p2.r)) / 2;
        return 0;
    }
    if (sqrt((p1 - p2).len()) - p1.r - p2.r > 0){   
        cout << fixed << (sqrt((p1 - p2).len()) - p1.r - p2.r) / 2;
        return 0;
    }
    cout << 0;
    //cout.precision(15);
    //if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2)) - r1 - r2 > 0)
//      cout << fixed << (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2)) - r1 - r2) / 2; 
    //else
    //  cout << 0;
    return 0;

}