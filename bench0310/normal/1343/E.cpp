#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,a,b,c;
        scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
        vector<ll> p(m);
        for(int i=0;i<m;i++) scanf("%I64d",&p[i]);
        sort(p.begin(),p.end());
        vector<vector<int>> v(n+1);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> da(n+1,-1);
        vector<int> db(n+1,-1);
        vector<int> dc(n+1,-1);
        auto bfs=[&](int src,vector<int> &d)
        {
            queue<int> q;
            q.push(src);
            d[src]=0;
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                for(int to:v[x])
                {
                    if(d[to]!=-1) continue;
                    d[to]=d[x]+1;
                    q.push(to);
                }
            }
        };
        bfs(a,da);
        bfs(b,db);
        bfs(c,dc);
        vector<ll> sum(m+1,0);
        for(int i=1;i<=m;i++) sum[i]=sum[i-1]+p[i-1];
        auto solve=[&](int l,int r)->ll
        {
            if(r>m) return (1ll<<60);
            return sum[min(m,l)]+sum[min(m,r)];
        };
        int cnt=m;
        ll res=(1ll<<60);
        for(int i=1;i<=n;i++) res=min(res,solve(db[i],da[i]+db[i]+dc[i]));
        printf("%I64d\n",res);
    }
    return 0;
}