#include <iostream>
#include <cmath>
using namespace std;
const double eps=1e-9;

int main()
{
    double d,h,v,e,pi=4*atan(1.0);
    cin>>d>>h>>v>>e;
    double inc=pi*(d/2)*(d/2)*e, dec=v;
    if(inc>dec||abs(inc-dec)<eps)
        cout<<"NO";
    else
    {
        cout.precision(5);
        cout<<"YES\n"<<fixed<<pi*(d/2)*(d/2)*h/(dec-inc);
    }
    return 0;
}