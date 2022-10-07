#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   int cnt = 0;
    long double vp, vd, t, f, c, d, s, t1;
    cin >> vp >> vd >> t >> f >> c;
    if (vd <= vp){
        cout << 0;
        return 0;
    }
    d = vp * t;
    s = d + (d / (vd - vp)) * vp;
    while (s < c){
        t1 = (s / vd) + f;
        s = s + (t1 * vp) + ((s + (t1 * vp)) / (vd - vp) * vp);
        cnt++;
    }
    cout << cnt;
    return 0;
}