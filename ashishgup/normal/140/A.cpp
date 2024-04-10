#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

int n, R, r;

double dist(double x1, double y1, double x2, double y2)
{
    double ans=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return ans;
}

bool check()
{
    double pi=acosl(-1);
    if(r>R)
        return 0;
    if(n==1)
        return 1;
    double x1, x2, y1, y2;
    x1=R-r;
    y1=0;
    x2=(R-r)*cosl(2*pi/n);
    y2=(R-r)*sinl(2*pi/n);
    if(dist(x1, y1, x2, y2)>=4*r*r)
        return 1;
    return 0;
}

int32_t main()
{ 
    IOS;
    cin>>n>>R>>r;
    if(check())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}