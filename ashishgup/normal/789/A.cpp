#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,p;
    long long ans=0;
    cin>>n>>k;

    while(n--)
    {
        cin>>p;
        ans+=ceil(((long double)p/k));
    }
    ans=ceil(((long double)ans)/2);
    cout<<ans;
    return 0;
}