#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;

    cout<<fixed<<setprecision(8)<<((a*d)/(a*d+b*c-a*c))<<'\n';

    return 0;
}