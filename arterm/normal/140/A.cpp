#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double R,r,w;
    long n;
    cin>>n>>R>>r;
    if (R<r){
        cout<<"NO\n";
        return 0;
    }
    if (R<2*r){
        if (n==1)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        return 0;
    }
    w=2*asin(r/(R-r));
    if (w*n<=8*atan(1)+1e-7)
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}