#include <iostream>
#include <algorithm>

#define M 121

using namespace std;

long n,a[M];

int main()
{
    long s=0,t=0,p=0;
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i];
    sort(a,a+n);
    while (t<n && s+a[t]<=710){
        s+=a[t++];
        if (s>350)
        p=p+s-350;
    }
    cout<<t<<" "<<p<<"\n";
    return 0;
}