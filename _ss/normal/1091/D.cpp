#include <iostream>

using namespace std;
const int sd=998244353;
int main()
{
    long long n;
    cin>>n;
    long long t=n,t2=0,t3=1;;
    for (long long i=1;i<=n;i++) t=(t*i)%sd;
    for (long long i=n;i>=2;i--)
    {
        t3=(t3*i)%sd;
        t2=(t2+t3)%sd;
    }
    t=t-t2;
    if (t<0) t=t+sd;
    cout<<t;
    return 0;
}