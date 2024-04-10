#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,a,b;
        scanf("%d%d%d%d",&n,&m,&a,&b);
        vector<int> v[n+1];
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> x(n+1,0);
        auto bfs=[&](int src,int val)->void
        {
            queue<int> q;
            vector<bool> vis(n+1,0);
            vis[a]=vis[b]=1;
            q.push(src);
            while(!q.empty())
            {
                int e=q.front();
                q.pop();
                for(int to:v[e])
                {
                    if(vis[to]) continue;
                    x[to]|=val;
                    vis[to]=1;
                    q.push(to);
                }
            }
        };
        bfs(a,1);
        bfs(b,2);
        long long c=0,d=0;
        for(int i=1;i<=n;i++)
        {
            if(i==a||i==b) continue;
            c+=(x[i]==1);
            d+=(x[i]==2);
        }
        printf("%I64d\n",c*d);
    }
    return 0;
}