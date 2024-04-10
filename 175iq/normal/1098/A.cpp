    #include<bits/stdc++.h>
    using namespace std;
    const int maxn=1e5+10;
    int a[maxn],s[maxn];
    vector<int>G[maxn];
    int n;
    void dfs(int v,int fa)
    {
        if(s[v]==-1&&G[v].size())
        {
            int mx=1e9+10;
            for(int i=G[v].size()-1;i>=0;i--)
            {
                int to=G[v][i];
                mx=min(mx,s[to]);
            }
            s[v]=mx;
        }
        else if(s[v]==-1)
            s[v]=s[fa];
        for(int i=G[v].size()-1;i>=0;i--)
            dfs(G[v][i],v);
        a[v]=s[v]-s[fa];
    }
    int main()
    {
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
        {
            int fa;scanf("%d",&fa);
            G[fa].push_back(i);
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&s[i]);
        dfs(1,0);
        long long ans=0;bool flag=1;
        for(int i=1;i<=n;i++)
        {
            ans+=a[i];
            if(a[i]<0) flag=0;
        }
        if(!flag) printf("-1");
        else printf("%lld\n",ans);
        return 0;
    }