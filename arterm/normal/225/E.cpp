#include <iostream>

#define p 1000000007
#define long long long

using namespace std;

long a[]={1,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011,24036583};

long pow(long x){
    long b=1,t=1,a=2;
    while (t<=x){
        if (t&x)
        b*=a;
        b%=p;
        a*=a;
        a%=p;
        t<<=1;
    }
    return b;
}

int main()
{
    long n;
    cin>>n;
    cout<<(pow(a[n]-1)+p-1)%p;
    return 0;
}