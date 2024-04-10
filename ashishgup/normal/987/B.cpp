#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define double long double

int32_t main()
{
    IOS;
    int x, y;
    cin>>x>>y;
    double lhs=y*logl(x);
    double rhs=x*logl(y);
    if(fabs(lhs-rhs)<1e-12)
        cout<<"=";
    else if(lhs>rhs)
        cout<<">";
    else
        cout<<"<";
    return 0;
}