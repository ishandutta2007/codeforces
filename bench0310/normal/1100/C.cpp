#include <bits/stdc++.h>

using namespace std;

int main()
{
    const double PI=3.1415926535;
    double n,r,x;
    cin >> n >> r;
    x=-(r*sin(PI/n))/(sin(PI/n)-1.0);
    cout << fixed << setprecision(9) << x << endl;
    return 0;
}