#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        map<int,int>mp;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            sum+=k;
            mp[k]++;
        }
        if(sum*2%n)
        {
            printf("0\n");
        }
        else
        {
            sum=sum*2/n;
            long long ans=0;
            for(auto pr:mp)
            {
                if(sum==2*pr.first)ans+=pr.second*(pr.second-1ll);
                else ans+=pr.second*1ll*mp[sum-pr.first];
            }
            ans/=2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}