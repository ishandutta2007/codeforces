#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    long n,m;
    cin>>n>>m;
    if (n<m)
    swap(n,m);
    if (m==1)
    cout<<n;
    if (m==2)
    switch (n%4){
           case 0: cout<<n; break;
           case 1: cout<<n+1; break;
           case 2: cout<<n+2; break;
           case 3: cout<<n+1; break;
           }
    if (m>2)
    cout<<(n*m+1)/2;
    return 0;
}