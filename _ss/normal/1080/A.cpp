#include <iostream>

using namespace std;

int main()
{
    long long n,k,t,d=0;
    cin>>n>>k;
    t=n*2;
    d=d+t/k;
    if (t%k>0) d++;
    t=n*5;
    d=d+t/k;
    if (t%k>0) d++;
    t=n*8;
    d=d+t/k;
    if (t%k>0) d++;
    cout<<d;
    return 0;
}