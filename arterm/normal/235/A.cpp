#include <iostream>

#define long long long

using namespace std;

long gcd(long x, long y){
    while (x!=0){
        y%=x;
        swap(x,y);
    }
    return x+y;
}

long lcm(long x, long y){
    return x/gcd(x,y)*y;
}


int main()
{
    long a,b,c,n,d=0;
    cin>>n;

    for (long a=n; a>0 && a>n-10; a--)
    for (long b=n; b>0 && b>n-10; b--)
    for (long c=n; c>0 && c>n-10; c--)
    d=max(d,lcm(lcm(a,b),c));

    cout<<d;


    return 0;
}