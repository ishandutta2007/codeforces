#include <iostream>

using namespace std;

bool good(long x, long y){
    return x-1<=y && y<=2*(x+1);
}



int main()
{
    long a1,a2,b1,b2;
    cin>>a1>>a2>>b2>>b1;
    if (good(a1,b1)||good(a2,b2))
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}