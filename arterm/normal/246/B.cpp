#include <iostream>

#define M 100100

using namespace std;

long n,s=0;

int main()
{
    cin>>n;
        for (long a,i=0; i<n; ++i){
            cin>>a;
            s+=a;
        }
    s%n==0 ? cout<<n:cout<<n-1;
    return 0;
}