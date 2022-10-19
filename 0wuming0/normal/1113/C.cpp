#include"bits/stdc++.h"
using namespace std;
int a[300005];
int s[300005];
map<int,int>mp;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        s[i]=s[i-1]^a[i];
    }//for(int i=0;i<=n;i++)cout<<s[i]<<" ";cout<<endl;
    long long ans=0;
    for(int i=0;i<=n;i+=2)
    {
        mp[s[i]]++;
    }
    for(auto pr:mp)
    {
        ans+=pr.second*(pr.second-1ll)/2;
    }
    mp.clear();
    for(int i=1;i<=n;i+=2)
    {
        mp[s[i]]++;
    }
    for(auto pr:mp)
    {
        ans+=pr.second*(pr.second-1ll)/2;
    }
    cout<<ans<<endl;
    return 0;
}