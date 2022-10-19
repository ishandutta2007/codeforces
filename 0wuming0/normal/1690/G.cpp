#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        map<int,int>mp;
        mp[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            auto it=mp.end();
            it--;
            if(it->second>a[i])mp[i]=a[i];
        }
        for(int i=1;i<=q;i++)
        {
            int k,d;
            scanf("%d%d",&k,&d);
            a[k]-=d;
            if(mp.find(k)!=mp.end())
            {
                mp[k]=a[k];
                while(1)
                {
                    auto it=mp.upper_bound(k);
                    if(it==mp.end()||a[k]>it->second)break;
                    else mp.erase(it);
                }
            }
            else
            {
                auto it=mp.upper_bound(k);
                it--;
                if(it->second>a[k])
                {
                    mp[k]=a[k];
                    while(1)
                    {
                        auto it=mp.upper_bound(k);
                        if(it==mp.end()||a[k]>it->second)break;
                        else mp.erase(it);
                    }
                }
            }
            printf("%d%c",(int)mp.size()," \n"[i==q]);
        }
    }
    return 0;
}