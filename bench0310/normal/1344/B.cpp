#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char s[n][m+1];
    for(int o=0;o<n;o++) scanf("%s",s[o]);
    bool ok=1;
    bool r=0;
    for(int o=0;o<n;o++)
    {
        bool x=0;
        for(int i=0;i<m;i++)
        {
            if(s[o][i]=='#')
            {
                if(x==0) x=1;
                else if(s[o][i-1]!='#') ok=0;
            }
        }
        if(x==0) r=1;
    }
    bool c=0;
    for(int i=0;i<m;i++)
    {
        bool x=0;
        for(int o=0;o<n;o++)
        {
            if(s[o][i]=='#')
            {
                if(x==0) x=1;
                else if(s[o-1][i]!='#') ok=0;
            }
        }
        if(x==0) c=1;
    }
    if(r!=c) ok=0;
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    int res=0;
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    auto in=[&](int a,int b)->bool
    {
        return (0<=a&&a<n&&0<=b&&b<m);
    };
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(s[o][i]=='.'||vis[o][i]==1) continue;
            queue<array<int,2>> q;
            q.push({o,i});
            vis[o][i]=1;
            while(!q.empty())
            {
                auto [a,b]=q.front();
                q.pop();
                for(auto [d,e]:z)
                {
                    if(in(a+d,b+e)&&vis[a+d][b+e]==0&&s[a+d][b+e]=='#')
                    {
                        vis[a+d][b+e]=1;
                        q.push({a+d,b+e});
                    }
                }
            }
            res++;
        }
    }
    if(ok) printf("%d\n",res);
    else printf("-1\n");
    return 0;
}