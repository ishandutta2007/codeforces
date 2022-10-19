#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int sqr(int x){
    int r = (int) sqrt(x) - 2;
    if (r < 0)
        r = 0;
    while (r*r < x)
        ++r;

    if (r*r>x)
        return -1;
    return r;
}


int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    int a, b;
    cin >> a >> b;
    for (int x = 1; x <= a; ++x){
        int y = sqr(a*a - x*x);
        if (x*x+y*y != a*a)
            continue;

        int x1 = -y;
        int y1 = x;

        if ((x1*b) % a != 0)
            continue;

        if ((y1*b) % a != 0)
            continue;

        x1 = (x1*b) / a;
        y1 = (y1*b) / a;

        if (x1 == 0 || y1 == 0 || x == 0 || y == 0)
            continue;

        if (x1 == x || y1 == y)
            continue;

        cout << "YES\n";
        cout << "0 0\n";
        cout << x << " " << y << "\n";
        cout << x1 << " " << y1 << "\n";
        return 0;
    }

    cout << "NO\n";

    return 0;
}