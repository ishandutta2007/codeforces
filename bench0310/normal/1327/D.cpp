#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        vector<int> col(n+1,0);
        for(int i=1;i<=n;i++) scanf("%d",&col[i]);
        vector<bool> vis(n+1,0);
        int res=n;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            vis[i]=1;
            vector<int> cycle={i};
            set<int> s;
            s.insert(col[i]);
            int c=col[i];
            bool ok=1;
            while(vis[p[cycle.back()]]==0)
            {
                cycle.push_back(p[cycle.back()]);
                vis[cycle.back()]=1;
                if(col[cycle.back()]!=c) ok=0;
            }
            int m=cycle.size();
            if(ok) res=1;
            for(int j=1;j<=m;j++) //jump
            {
                if(j>=res) break;
                int cnt=gcd(j,m);
                if(cnt==1) continue;
                for(int st=0;st<cnt;st++)
                {
                    if(j>=res) break;
                    c=col[cycle[st]];
                    ok=1;
                    for(int now=(st+j)%m;now!=st;now=(now+j)%m)
                    {
                        if(col[cycle[now]]!=c)
                        {
                            ok=0;
                            break;
                        }
                    }
                    if(ok) res=min(res,j);
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}