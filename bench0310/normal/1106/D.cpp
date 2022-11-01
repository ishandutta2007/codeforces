#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v[n+1];
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        if(x==y) continue;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool b[n+1];
    for(int i=0;i<=n;i++) b[i]=0;
    vector<int> res;
    res.push_back(1);
    b[1]=1;
    set<int> s;
    for(int i=0;i<(int)v[1].size();i++) s.insert(v[1][i]);
    while((int)res.size()<n)
    {
        int e=*(s.begin());
        b[e]=1;
        s.erase(e);
        res.push_back(e);
        for(int i=0;i<(int)v[e].size();i++) if(!b[v[e][i]]) s.insert(v[e][i]);
    }
    for(int i=0;i<n;i++) printf("%d ",res[i]);
    printf("\n");
    return 0;
}