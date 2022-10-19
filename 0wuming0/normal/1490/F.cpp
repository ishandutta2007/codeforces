#include"bits/stdc++.h"
using namespace std;
map<int,int>mp;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            map<int,int>::iterator it;
            int x;
            scanf("%d",&x);
            it=mp.find(x);
            if(it==mp.end())
            {
                mp[x]=1;
            }
            else it->second++;
            a[i]=0;
        }
        a[n]=0;
        int sum=0;
        int now=0;
        int ans=1e9;
        int sum2=0;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
        {
            a[it->second]++;
            sum+=(it->second);
        }
        for(int i=n;i>=0;i--)
        {
            sum-=a[i]*i;
            sum2+=now;
            now+=a[i];
            ans=min(ans,sum+sum2);
        }
        cout<<ans<<endl;
    }
    return 0;
}