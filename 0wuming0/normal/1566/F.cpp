#include"bits/stdc++.h"
using namespace std;
#define ll long long
struct node
{
    int l,r;
    int type;
}p[400005];
bool cmp(node x,node y)
{
    if(x.l==y.l)
    {
        if(x.type!=y.type)return x.type>y.type;
        return x.r>y.r;
    }
    return x.l<y.l;
}
ll ans;
ll dp[400005][2];
void solve(int l,int r)
{
    int now=0;
    int inx;
    if(p[l].type==0)
    {
        inx=l;
        dp[0][0]=0;
        dp[0][1]=0;
        l++;
        now++;
    }
    else
    {
        inx=-l-1;
    }
    for(;l<=r;l++)
    {
        if(p[l].type==0)
        {
            if(inx<0)
            {
                dp[now][0]=(p[l].l-p[-inx-1].r)*2ll;
                dp[now][1]=p[l].l-p[-inx-1].r;
                now++;
                inx=l;
                continue;
            }
            dp[now][0]=min(dp[now-1][0],dp[now-1][1])+(p[l].l-p[inx+1].r)*2ll;
            dp[now][1]=min(dp[now-1][0],dp[now-1][1])+(p[l].l-p[inx+1].r);
            for(int i=inx+1;i<l;i++)
            {
                ll k=min(dp[now-1][0]+(p[i].l-p[inx].l),dp[now-1][1]+2ll*(p[i].l-p[inx].l));
                dp[now][0]=min(k+(p[l].l-p[i+1].r)*2ll,dp[now][0]);
                dp[now][1]=min(k+(p[l].l-p[i+1].r),dp[now][1]);
            }
            inx=l;
            now++;
        }
    }
    ans+=min(dp[now-1][0]+(p[r].l-p[inx].l),dp[now-1][1]+(p[r].l-p[inx].l)*2ll);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        set<int>st;
        map<int,int>mp;
        int n,m;
        int nn=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d",&a);
            b=a;
            p[nn].l=a;
            p[nn].r=b;
            p[nn++].type=0;
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d",&a);
            scanf("%d",&b);
            p[nn].l=a;
            p[nn].r=b;
            p[nn++].type=1;
        }
        sort(p,p+nn,cmp);
        for(int i=0;i<n+m;i++)
        {
            if(p[i].type)
            {
                st.insert(i);
            }
            else
            {
                for(auto k:st)if(p[k].r>=p[i].r)p[k].type=-1;
                st.clear();
            }
        }
        st.clear();
        for(int i=0;i<n+m;i++)
        {
            if(p[i].type)
            {
                st.insert(p[i].l);
            }
        }
        nn=0;
        for(auto k:st)mp[k]=nn++;
        for(int i=0;i<=n+m;i++)
        {
            dp[i][0]=2e9;
        }
        for(int i=0;i<n+m;i++)
        {
            if(p[i].type)
            {
                dp[mp[p[i].l]][0]=min(p[i].r,(int)dp[mp[p[i].l]][0]);
            }
        }
        for(int i=nn-1;i>0;i--)dp[i-1][0]=min(dp[i-1][0],dp[i][0]);
        for(int i=0;i<n+m;i++)
        {
            if(p[i].type)
            {
                if(dp[mp[p[i].l]][0]!=p[i].r)
                {
                    p[i].type=-1;
                }
            }
        }
        mp.clear();
        for(int i=0;i<n+m;i++)
        {
            if(p[i].type)
            {
                if(mp.find(p[i].r)!=mp.end())mp[p[i].r]=max(p[i].l,mp[p[i].r]);
                else mp[p[i].r]=p[i].l;
            }
        }
        for(int i=0;i<n+m;i++)
        {
            if(p[i].type)
            {
                if(mp[p[i].r]!=p[i].l)
                {
                    p[i].type=-1;
                }
            }
        }
        nn=0;
        for(int i=0;i<n+m;i++)
        {
            if(p[i].type!=-1)
            {
                p[nn++]=p[i];
            }
        }
        int now=0;
        for(int i=1;i<nn;i++)
        {
            if(p[i-1].type|p[i].type);
            else
            {
                solve(now,i-1);
                now=i;
            }
        }
        solve(now,nn-1);
        printf("%lld\n",ans);
        ans=0;
    }
    return 0;
}