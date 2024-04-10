#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define double long double

const int N=2e5+5;

double R, x1, y1, x2, y2, r;

double distance(double x3, double y3, double x4, double y4)
{
    double xdiff=(x3-x4)*(x3-x4);
    double ydiff=(y3-y4)*(y3-y4);
    double ans=sqrtl(xdiff + ydiff);
    return ans;
}

pair<double, double> getcoords()
{
    double xdiff=x1 - x2;
    double ydiff=y1 - y2;
    double dist=distance(x1, y1, x2, y2);
    if(fabs(dist)<1e-3)
    {
        double xreqd=x2 + R/2;
        double yreqd=y2;
        return {xreqd, yreqd};
    }
    xdiff/=dist;
    ydiff/=dist;
    double xreqd=x2 + r * xdiff;
    double yreqd=y2 + r * ydiff;
    return {xreqd, yreqd};
}

int32_t main()
{
    IOS;
    while(cin>>R>>x1>>y1>>x2>>y2)
    {
        if(distance(x2, y2, x1, y1)>R)
        {
            cout<<fixed<<setprecision(12)<<x1<<" "<<y1<<" "<<R<<endl;
            continue;
        }
        double dist=distance(x1, y1, x2, y2);
        r=dist + R;
        r/=2;
        pair<double, double> p = getcoords();
        cout<<fixed<<setprecision(12)<<p.first<<" "<<p.second<<" "<<r<<endl;
    }
    return 0;
}