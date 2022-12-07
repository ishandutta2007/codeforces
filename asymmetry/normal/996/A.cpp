#include <bits/stdc++.h>

using namespace std;

int n, l;

int main()
{
    cin>>n;
    l+=n/100;
    n%=100;
    l+=n/20;
    n%=20;
    l+=n/10;
    n%=10;
    l+=n/5;
    n%=5;
    l+=n;
    cout<<l;
    return 0;
}