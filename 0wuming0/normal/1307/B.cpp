#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            mp[a]=1;
        }
        if(mp.find(m)!=mp.end())
        {
            cout<<1<<endl;
        }
        else
        {
            auto it=mp.end();
            it--;
            int k=it->first;
            int ans=m/k;
            if(m%k)ans++;
            cout<<max(ans,2)<<endl;
        }
    }
    return 0;
}