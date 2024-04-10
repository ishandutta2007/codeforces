#include <iostream>

using namespace std;

int main()
{
    long long n,t=0;
    cin>>n;
    for (int i=2;i<=n/2;i++) t=t+((n/i)*(n/i+1)/2-1)*4;
    cout<<t;
    return 0;
}