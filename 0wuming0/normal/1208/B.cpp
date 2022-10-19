#include"bits/stdc++.h"
using namespace std;
int a[2005];
map<int,int>mp;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        mp[a[i]]=0;
    }
    int ans=0;
    for(int j=n;j>=1;j--)
    {
        mp[a[j]]++;
        if(mp[a[j]]>=2)break;
        ans++;
    }
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        mp[a[i]]++;
        if(mp[a[i]]==2)break;
        int j;
        for(j=n;;j--)
        {
            mp[a[j]]++;
            if(mp[a[j]]>=2)break;
        }
        ans=max(ans,n-j+i);
        while(j<=n)mp[a[j++]]--;
    }
    cout<<n-ans<<endl;
    return 0;
}