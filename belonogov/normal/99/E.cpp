#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const long double eps = 1 / 1e7;
struct point
{
    long double x, y;
};
long double a, b, l;
point p;

long double ptl(long double k)
{
    point p1, p2;
    p1.x = 0;
    p1.y = sqrt(l * l - k * k);
    p2.x = k;
    p2.y = 0;
    long double A, B, C;
    A = p1.y - p2.y;
    B = p2.x - p1.x;
    C = - A * p1.x - B * p1.y;
    return ((A * p.x + B * p.y + C)) / sqrt(A * A + B * B);
}

long double trin()
{
    long double ll = 0, rr = l, k1, k2, d1, d2;
    while (rr - ll > eps)
    {
        k1 = ll * 2 / 3 + rr / 3;
        k2 = ll / 3 + rr * 2 / 3;
        d1 = ptl(k1);
        d2 = ptl(k2);
        if (d1 > d2)
            ll = k1;
        else
            rr = k2;
    }

    return ptl(rr);
}

int main()
{
    long double w, k;
    cin >> a >> b >> l;
    //cin >> k;
    p.x = a;
    p.y = b;
  //  cout << ptl(k);
   // cout << "\n" << l;
    if (a >= l)
    {
        cout << min(l, b);
        return 0;
    }
    if (b >= l)
    {
        cout << min(l, a);
        return 0;
    }
    w = trin();
    if (w  < eps)
    {
        cout << "My poor head =(";
        return 0;
    }
    cout.precision(15);
    cout << w;
    return 0;
}