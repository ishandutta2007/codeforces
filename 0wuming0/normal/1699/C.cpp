#include"bits/stdc++.h"
using namespace std;
long long mod=1e9+7;
int a[100005];
int pos[100005];
bool vis[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        int l,r;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            if(a[i])mp[i]=a[i];
            pos[a[i]]=i;
            vis[i]=0;
        }
        vis[n]=0;
        long long ans=1;
        vis[0]=1;
        l=r=pos[0];
        mp[n]=0;
        int now=1,num=0;
        while(now!=n)
        {
            l=min(pos[now],l);
            r=max(pos[now],r);
            while(1)
            {
                auto it=mp.lower_bound(l);
                if(it->first>r)break;
                vis[it->second]=1;
                num++;
                mp.erase(it);
            }
            num--;
            now++;
            while(vis[now]==1)
            {
                ans=ans*num%mod;
                num--;
                now++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}