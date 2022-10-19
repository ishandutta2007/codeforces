#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)

    {
        int n;
        cin>>n;long long i;
        int ans=0;
        for(i=10;i<=n;i*=10)
        {
            ans+=9;
        }
        for(long long j=(i-1)/9;j<=n;j+=(i-1)/9)
        {
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}