#include <cstdlib>
#include <iostream>

using namespace std;

bool good(long x, long k){
     if (k==1)
     return 1;
     for (long i=2; i*i<=x; ++i)
     if (x%i==0)
     if (x/i>=k)
     return 1;
     else
     return 0;
     return 0;
     }

int main()
{
    long n,m,k;
    cin>>n>>m>>k;
    if (!good(m,k) || m==1){
                    cout<<"Marsel";
                    return 0;
                    }
    if (n%2==0)
    cout<<"Marsel";
    else
    cout<<"Timur";
    return 0;
}