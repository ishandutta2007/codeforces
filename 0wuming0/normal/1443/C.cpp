#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[200005];
int b[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        multimap<int,int>mp;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)scanf("%d",b+i);
        for(int i=0;i<n;i++)
        {
            pair<int,int>pr;
            pr.first=a[i];
            pr.second=b[i];
            mp.insert(pr);
        }
        ll ans=1e18;
        ll sum=0;
        while(mp.size())
        {
            auto it=mp.end();
            it--;
            ans=min(ans,max((ll)it->first,sum));
            if(sum>=it->first)break;
            sum+=it->second;
            mp.erase(it);
        }
        ans=min(ans,sum);
        cout<<ans<<endl;
    }
    return 0;
}