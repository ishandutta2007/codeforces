#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    const ll mod=998244353;
    ll res=0;
    for(int o=2;o<=n;o++)
    {
        vector<int> one[2*n+1];
        vector<int> two[2*n+1];
        auto add=[&](int a,int b,int t)
        {
            (t==0?one[a]:two[a]).push_back(b);
            (t==0?one[b]:two[b]).push_back(a);
        };
        for(int j=1;j<=n-j+1;j++) add(j,n-j+1,0);
        for(int j=o;j<=n-j+o;j++) add(n+j,n+n-j+o,0);
        for(int i=1;i<=n;i++) if(s[i]=='0') add(i,i+n,0);
        vector<int> g(2*n+1,0);
        int id=1;
        function<void(int)> dfs1=[&](int a)
        {
            g[a]=id;
            for(int to:one[a]) if(g[to]==0) dfs1(to);
        };
        for(int i=1;i<=2*n;i++)
        {
            if(g[i]==0)
            {
                dfs1(i);
                id++;
            }
        }
        for(int i=1;i<=n;i++) if(s[i]=='1') add(g[i],g[n+i],1);
        vector<int> c(id,-1);
        bool ok=1;
        function<void(int)> dfs2=[&](int a)
        {
            for(int to:two[a])
            {
                if(c[to]==-1)
                {
                    c[to]=1-c[a];
                    dfs2(to);
                }
                if(c[to]==c[a]) ok=0;
            }
        };
        for(int i=1;i<id;i++)
        {
            if(c[i]==-1)
            {
                c[i]=0;
                dfs2(i);
            }
        }
        if(ok==0) continue;
        for(int i=1;i<=n;i++) if(s[i]=='1') add(i,n+i,0);
        vector<int> comp(2*n+1,0);
        id=1;
        function<void(int)> dfs3=[&](int a)
        {
            comp[a]=id;
            for(int to:one[a]) if(comp[to]==0) dfs3(to);
        };
        for(int i=1;i<=2*n;i++)
        {
            if(comp[i]==0)
            {
                dfs3(i);
                id++;
            }
        }
        map<int,int> req;
        auto go=[&](int i,int t)->bool
        {
            if(req.find(comp[i])!=req.end()) return (req[comp[i]]==(t^c[g[i]]));
            req[comp[i]]=t^c[g[i]];
            return 1;
        };
        for(int i=1;i<o;i++) ok&=go(n+i,0);
        ok&=go(1,1);
        ok&=go(n+o,1);
        if(ok==0) continue;
        int p=id-1-req.size();
        ll x=1;
        while(p--) x=(2*x)%mod;
        res=(res+x)%mod;
    }
    cout << res << "\n";
    return 0;
}