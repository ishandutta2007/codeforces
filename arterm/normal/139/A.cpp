#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    long n, a[10], i;
    cin>>n;
    for (i=0; i<7; ++i)
    cin>>a[i];
    for (i=0; n>0; ++i){
        if (i==7)
        i=0;
        n-=a[i];
        }
    cout<<i;
    return 0;
}