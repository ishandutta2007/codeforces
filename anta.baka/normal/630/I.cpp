#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    cin>>n;
    unsigned long long ans=0;
    ans=24*(unsigned long long)pow(4.0,n-3);
    if(n>3)
        ans+=36*(unsigned long long)pow(4.0,n-4)*(n-3);
    cout<<ans;
    return 0;
}