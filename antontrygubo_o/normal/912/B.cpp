#include <iostream>

using namespace std;

int main()
{

long long n, k;
cin>>n>>k;
if (k==1) cout<<n;
if (k>1)
{
    long long a = 1;
    while (n) {n/=2; a*=2;}
    cout<<a-1;
}

}