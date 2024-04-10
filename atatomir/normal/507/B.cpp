#include <iostream>
#include <cmath>

using namespace std;

#define eps 0.000000001

double x,y,x2,y2,r,d;
long long ans;

int main()
{
    cin >> r >> x >> y >> x2 >> y2;
    r *= 2;
    d =sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));

    d/= r;
    ans = (long long) d;
    if(d-1.00*ans>0) ans++;

    cout << ans;

    return 0;
}