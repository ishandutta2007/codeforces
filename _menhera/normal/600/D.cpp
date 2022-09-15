#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double C(long double a, long double b, long double c)
{
    return acosl((a*a+b*b-c*c)/(2*a*b));
}

int main()
{
    cout << fixed << setprecision(12);
    const long double PI = atan2(0, -1);

    long double x1, y1, r1; cin >> x1 >> y1 >> r1;
    long double x2, y2, r2; cin >> x2 >> y2 >> r2;

    long double D = hypot(x1-x2, y1-y2);
    if(D >= r1+r2)
    {
        cout << 0.0 << endl;
        return 0;
    }
    if(D <= abs(r1-r2))
    {
        cout << PI*min(r1, r2)*min(r1, r2) << endl;
        return 0;
    }

    long double t1 = C(r1, D, r2), t2 = C(r2, D, r1);
    cout << r1*r1*(t1-sinl(t1)*cosl(t1)) + r2*r2*(t2-sinl(t2)*cosl(t2)) << endl;

}