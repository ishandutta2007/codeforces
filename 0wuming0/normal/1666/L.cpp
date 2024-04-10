#include"bits/stdc++.h"
using namespace std;
vector<int>v[200005];
int vis[200005];
int bg[200005];
int ansi,ansj;
void dfs(int i,int fa)
{//cout<<"<<"<<fa<<" "<<i<<endl;
    vis[i]=fa;
    bg[i]=bg[fa];
    for(auto &j:v[i])if(vis[j]==0)
    {
        dfs(j,i);
    }
    else if(bg[j]!=bg[fa])
    {
        ansi=i;
        ansj=j;//cout<<"??"<<ansi<<" "<<ansj<<endl;
    }
}
int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(b!=s)v[a].push_back(b);
    }
    for(auto &i:v[s])if(vis[i]==0)
    {
        bg[s]=i;
        dfs(i,s);
    }
    else
    {
        ansi=s;
        ansj=i;
    }
    if(ansi)
    {
        cout<<"Possible"<<endl;
        vector<int>v1,v2;
        for(int i=ansj;i!=s;i=vis[i])v1.push_back(i);
        v2.push_back(ansj);
        for(int i=ansi;i!=s;i=vis[i])v2.push_back(i);
        v1.push_back(s);v2.push_back(s);
        for(int i=0,j=v1.size()-1;i<j;i++,j--)swap(v1[i],v1[j]);
        for(int i=0,j=v2.size()-1;i<j;i++,j--)swap(v2[i],v2[j]);
        cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();i++)printf("%d%c",v1[i]," \n"[i==v1.size()-1]);
        cout<<v2.size()<<endl;
        for(int i=0;i<v2.size();i++)printf("%d%c",v2[i]," \n"[i==v2.size()-1]);
    }
    else cout<<"Impossible"<<endl;
    return 0;
}
/*
5 6 2
2 1
5 3
3 4
1 5
4 2
2 5
*/