#include <bits/stdc++.h>

using namespace std;


main()
{
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    if (x > y){
        swap (a, b);
        swap (x, y);
    }
    int nn = n;
    int mx = 0, MX = 0;
    int t = nn / x;
    if (t > a)
        t = a;
    mx += t;
    nn -= t * x;
    t = nn / y;
    if (t > b)
        t = b;
    mx += t;
    nn -= t * y;
    nn = n;
    nn -= a * (x - 1) + b * (y - 1);
    if (nn < 0)
        nn = 0;
    cout << nn << " " << mx << endl;
    return 0;
}