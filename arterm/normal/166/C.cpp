#include <iostream>

using namespace std;

int main()
{
    long n,x,l=0,r=0,a;
    cin>>n>>x;
    for (long i=0; i<n; ++i){
        cin>>a;
        if (a<x)
        ++l;
        if (a>x)
        ++r;
    }
    for (a=0;!(l<(n+a+1)/2 && (n+a+1)/2<=n+a-r);++a);
    cout<<a;
    return 0;
}