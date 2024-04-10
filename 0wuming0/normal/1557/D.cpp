#include"bits/stdc++.h"
using namespace std;
struct _
{
    int l,r;
    int n;
}a[300005];
bool cmp(_ x,_ y)
{
    return x.l<y.l;
}
vector<int>v[300005];
int dp[300005];
int best[300005];
int ans[300005],save[300005],nn;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a[i].n,&a[i].l,&a[i].r);
    }
    sort(a,a+m,cmp);
    multiset<int>s;
    multimap<int,int>mp;
    s.insert(0);
    s.insert(n+1);
    mp.insert(make_pair((int)1e9+1,n+1));
    for(int i=0;i<m;i++)
    {
        while(a[i].l>mp.begin()->first)
        {
            auto it=s.find(mp.begin()->second);
            auto it2=it;
            it2--;
            v[*it2].push_back(*it);
            it2=it;
            it2++;
            v[*it].push_back(*it2);
            s.erase(it);
            mp.erase(mp.begin());
        }
        s.insert(a[i].n);
        mp.insert(make_pair(a[i].r,a[i].n));
    }
    while(mp.size()!=1)
    {
        auto it=s.find(mp.begin()->second);
        auto it2=it;
        it2--;
        v[*it2].push_back(*it);
        it2=it;
        it2++;
        v[*it].push_back(*it2);
        s.erase(it);
        mp.erase(mp.begin());
    }
    for(int i=n;i>=1;i--)
    {
        for(auto j:v[i])if(i!=j)
        {
            if(dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                best[i]=j;
            }
        }
    }
    int besti,sum=0;
    for(int i=1;i<=n;i++)if(dp[i]>sum)besti=i,sum=dp[i];
    while(besti!=n+1)
    {
        ans[besti]=1;
        besti=best[besti];
    }
    for(int i=1;i<=n;i++)if(ans[i]==0)save[nn++]=i;
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%d%c",save[i]," \n"[i==nn-1]);
    return 0;
}