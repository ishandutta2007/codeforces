#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
    long long n,d=0,i;
    cin>>n;
    if (n%2!=0)
    {
        d++;
        i=2;
        while (i<=sqrt(n) && n%i!=0) i++;
        if (i>sqrt(n) && n%i!=0) n=0; else n=n-i;
    }
    cout<<d+n/2;
    return 0;
}