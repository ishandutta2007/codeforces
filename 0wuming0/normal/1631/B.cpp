#include"bits/stdc++.h"
using namespace std;
int a[300005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=0;
        int now=n-1;
        while(1)
        {
            if(now<0)break;
            while(now>=0&&a[now]==a[n-1])now--;
            if(now<0)break;
            ans++;
            now=now+now-n+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}