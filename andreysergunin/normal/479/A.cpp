#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long a, b, c, p1, p2, p3, p4, p5, p6, ans;
    cin >> a >> b >> c;
    p1 = a + b + c;
    p2 = a * b + c;
    p3 = a + b * c;
    p4 = a * b * c;
    p5 = (a + b) * c;
    p6 = a * (b + c);
    ans = max (max (max (p1, p2), max (p3, p4)), max (p5, p6));
    cout << ans;
}