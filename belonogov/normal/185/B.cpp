#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
const int n = 500;
int a, b, c, s;

db solve(db x, db y, db z){
    //cerr << log(x) << "\n";
    //cerr << log(y) << "\n";
    //cerr << log(z) << "\n";
//  cerr << "\n";
    return a * log(x) + b * log(y) + c * log(z);
}

db ter(db x){
    db l, r, y, z, r1, r2;
    int i;
    l = 0;
    r = s - x;
    forn(i, n){
        y = (l + l + r) / 3;
        z = s - x - y;
        r1 = solve(x, y, z);
        
        y = (l + r + r) / 3;
        z = s - x - y;
        r2 = solve(x, y, z);
    
        if (r1 < r2)
            l = (l + l + r) / 3;
        else
            r = (l + r + r) / 3;
    }
    return (l + r) / 2;

}


int main(){
    int i;
    db l, r, x, y, z, r1, r2;
    cin >> s;
    cin >> a >> b >> c;

    l = 0;
    r = s;
    forn(i, n){
        x = (l + l + r) / 3;
        y = ter(x);
        z = s - x - y;
        r1 = solve(x, y, z);
        
        x = (l + r + r) / 3;
        y = ter(x);
        z = s - x - y;
        r2 = solve(x, y, z);
    
        if (r1 < r2)
            l = (l + l + r) / 3;
        else
            r = (l + r + r) / 3;
    }
    x = (l + r) / 2;
    y = ter(x);
    z = s - x - y;
    cout.precision(10);
    cout << fixed << x << " " << y << " " << z;
//  cout << "\n" << solve(x, y, z);
    return 0;

}