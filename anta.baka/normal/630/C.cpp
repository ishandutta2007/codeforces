#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long ans=0,pow=1;
    for(int i=1; i<=n; i++) {
        pow*=2;
        ans+=pow;
    }
    cout<<ans;
    return 0;
}