#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=a[0];
        for(int i=0;i<n;i++)ans=ans&a[i];
        cout<<ans<<endl;       
    }
    
    return 0;
}