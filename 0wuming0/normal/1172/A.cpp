#include"bits/stdc++.h"
using namespace std;
int a[200005];
int b[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)scanf("%d",b+i);
    int now=b[n];
    int flag=b[n];
    if(flag)
    for(int i=1;i<=now;i++)
    {
        if(i!=b[n-b[n]+i])
        {
            flag=0;
            break;
        }
    }
    if(flag==n)
    {
        cout<<0<<endl;
        return 0;
    }
    if(flag)
    {
        map<int,int>mp;
        for(int i=1;i<=n;i++)mp[a[i]]=1;
        for(int i=1;i<=n-b[n];i++)
        {
            if(mp.find(b[n]+i)==mp.end())
            {
                break;
            }
            mp[b[i]]=1;
            if(i==n-b[n])
            {
                cout<<n-b[n]<<endl;
                return 0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(b[i])
    {
        ans=max(ans,i-b[i]+1);
    }
    cout<<ans+n<<endl;
    return 0;
}
/*
3
0 0 3
0 1 2
*/