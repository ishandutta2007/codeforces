#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    cin>>n;
    unsigned long long c=(n-4)*(n-3)*(n-2)*(n-1)*n;
    cout<<c/120*c;
}