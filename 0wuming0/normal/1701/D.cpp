#include"bits/stdc++.h"
using namespace std;
int a[500005];
int n;
int solve1(int x,int y)
{
    int l=0,r=n;
    while(l+1!=r)
    {
        int m=l+r>>1;
        if(x/m>y)l=m;
        else r=m;
    }
    return r;
}
int solve2(int x,int y)
{
    int l=1,r=n+1;
    while(l+1!=r)
    {
        int m=l+r>>1;
        if(x/m>=y)l=m;
        else r=m;
    }
    return l;
}
int ans[500005];
int sr[500005];
vector<int>v[500005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            v[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            //i/?=a[i]
            int l=solve1(i,a[i]);
            int r=solve2(i,a[i]);
            //cout<<"<<"<<i<<" "<<a[i]<<" "<<l<<" "<<r<<endl;
            sr[i]=r;
            v[l].push_back(i);
        }
        multimap<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            for(auto j:v[i])
            {
                mp.insert(pair<int,int>(sr[j],j));
            }
            ans[mp.begin()->second]=i;
            mp.erase(mp.begin());
        }
        for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}