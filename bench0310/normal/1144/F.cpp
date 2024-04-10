#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[m],b[m];
    vector<int> v[n+1];
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    vector<bool> vis(n+1,0);
    vector<bool> col(n+1);
    queue<int> q;
    vis[1]=1;
    col[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        for(int i=0;i<(int)v[e].size();i++)
        {
            if(vis[v[e][i]]==0)
            {
                vis[v[e][i]]=1;
                col[v[e][i]]=(!col[e]);
                q.push(v[e][i]);
            }
            else if(col[v[e][i]]==col[e])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i=0;i<m;i++)
    {
        if(col[a[i]]) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}