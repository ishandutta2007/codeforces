#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld pi = 4*atan(1.0);
const ld eps = 1e-14;

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

ld dist(ld A, ld B, ld C, ld x, ld y)
{
    return (A*x+B*y+C)/(A*A+B*B)*(A*x+B*y+C);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    ld x0, y0;
    cin >> n >> x0 >> y0;
    ld x[n+1], y[n+1];
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];
    x[n] = x[0]; y[n] = y[0];
    ld dmin = dist(x0, y0, x[0], y[0]), dmax = dist(x0, y0, x[0], y[0]);
    for(int i=1; i<=n; i++)
    {
        ld OA = dist(x0, y0, x[i], y[i]);
        ld OB = dist(x0, y0, x[i-1], y[i-1]);
        ld OH = dist(y[i]-y[i-1], x[i-1]-x[i], y[i-1]*(x[i]-x[i-1]) - x[i-1]*(y[i]-y[i-1]), x0, y0);
        ld AB = dist(x[i], y[i], x[i-1], y[i-1]);
        dmin = min(dmin, OA);
        dmax = max(dmax, OA);
        if(OB<OA+AB && OA<OB+AB)
            dmin = min(dmin, OH);
    }
    cout.precision(6);
    cout<<fixed<<pi*(dmax-dmin);
    return 0;
}