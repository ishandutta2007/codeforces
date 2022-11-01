#include <iostream>
#include <vector>
using namespace std;
int n,m,p;
vector <pair<int,int> > e[110];
bool mark[110],color[110];
void dfs(int x,int y,int c)
{
    mark[x]=true;
    if(x==y)
    {
        if(color[c]==false)
        {
            p++;
            color[c]=true;
        }
        mark[x]=false;
        return ;
    }
    for(int i=0;i<e[x].size();i++)
        if(mark[e[x][i].first]==false && e[x][i].second==c)
            dfs(e[x][i].first,y,e[x][i].second);
    mark[x]=false;
    
}

int main()
{
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back(make_pair(b,c));
        e[b].push_back(make_pair(a,c));
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int u,v;
        p=0;
        cin>>u>>v;
        mark[u]=true;
        for(int j=0;j<e[u].size();j++)
        {
            dfs(e[u][j].first,v,e[u][j].second);
        }
        cout<<p<<endl;
        for(int i=0;i<110;i++)
            color[i]=mark[i]=0;
    }
    return 0;
}