#include"bits/stdc++.h"
using namespace std;
int a[105],b[105];
int tim[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
        }
        for(int i=1;i<=n;i++)cin>>tim[i];
        for(int i=1;i<=n;i++)
        {
            ans+=tim[i];
            if(i==n)break;
            ans-=(b[i]-a[i])/2;
            if(ans<0)ans=0;
        }
        cout<<a[n]+ans<<endl;
    }
    return 0;
}