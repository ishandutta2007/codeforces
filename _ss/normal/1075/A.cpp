#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n,x,y;
    cin>>n>>x>>y;
    if (max(abs(x-1),abs(y-1))<=max(abs(n-x),abs(n-y))) cout<<"White"; else cout<<"Black";
    return 0;
}