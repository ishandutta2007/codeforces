#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        map<int,int>sx,sy,null;
        map<int,map<int,int> >mpx;
        map<int,map<int,int> >mpy;
        int a;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            sx[a]=0;
            mpx[a]=null;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a);
            sy[a]=0;
            mpy[a]=null;
        }
        while(k--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            auto it=sx.lower_bound(a);
            if(it->first!=a)
            {
                it->second++;
                if(mpy[b].find(it->first)==mpy[b].end())
                {
                    mpy[b][it->first]=1;
                }
                else mpy[b][it->first]++;
            }
            it=sy.lower_bound(b);
            if(it->first!=b)
            {
                it->second++;
                if(mpx[a].find(it->first)==mpx[a].end())
                {
                    mpx[a][it->first]=1;
                }
                else mpx[a][it->first]++;
            }
        }
        ll ans=0;
        for(auto pr:sx)
        {
            ans+=pr.second*(pr.second-1ll)/2;
        }
        for(auto pr:sy)
        {
            ans+=pr.second*(pr.second-1ll)/2;
        }
        for(auto p:mpx)for(auto pr:p.second)
        {
            ans-=pr.second*(pr.second-1ll)/2;
        }
        for(auto p:mpy)for(auto pr:p.second)
        {
            ans-=pr.second*(pr.second-1ll)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}