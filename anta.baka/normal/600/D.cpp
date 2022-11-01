#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384;

int main()
{
    long double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if(r1 < r2) { swap(x1, x2); swap(y1, y2); swap(r1, r2); }
    long double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    cout.precision(9);
    if(d >= r1 + r2) { cout << 0; return 0; }
    if(r1 >= d + r2) { cout << pi * r2 * r2; return 0; }
    long double a1 = acos((r1*r1-r2*r2+d*d)/(2*r1*d)) * 2;
    long double s1 = (long double) 0.5 * r1 * r1 * a1 - 0.5 * r1 * r1 * sin(a1);
    long double a2 = acos((r2*r2-r1*r1+d*d)/(2*r2*d)) * 2;
    long double s2 = (long double) 0.5 * r2 * r2 * a2 - 0.5 * r2 * r2 * sin(a2);
    cout << s1 + s2;
    return 0;
}