#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    a=max(a,b);
    a=7-a;
    b=6;

    if(a%2==0 && b%2==0)
        a/=2,b/=2;
    if(a%3==0 && b%3==0)
        a/=3,b/=3;

    cout<<a<<'/'<<b<<'\n';
    return 0;
}