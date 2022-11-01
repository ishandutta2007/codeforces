#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    unsigned long long c=1LL*(n-4)*(n-3)*(n-2)*(n-1)*n/120;
    cout<<c+((n-5)*c/6)+((n-6)*(n-5)*c/42);
    return 0;
}