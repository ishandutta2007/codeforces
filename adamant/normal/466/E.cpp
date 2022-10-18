#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5;

int pr[MAXN];

int get(int x)
{return x==pr[x]?x:pr[x]=get(pr[x]);}

struct query
{
    int num,vertex,parent;
};

vector<query> Q[MAXN];
vector< int > G[MAXN];
int check[MAXN],ans[MAXN];
void dfs(int x,int h)
{
    check[x]=h;
    for(int i=0;i<Q[x].size();i++)
    {
        int a=check[Q[x][i].parent];
        int b=check[Q[x][i].vertex];
        ans[Q[x][i].num]=(a<=b);
    }
    for(int i=0;i<G[x].size();i++) dfs(G[x][i],h+1);
    check[x]=0;
}

main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    iota(pr,pr+n,0);
    int T=0,Z=0;
    int par[MAXN],ver[MAXN];
    int PAR[MAXN];
    while(m--)
    {
        int t,x,y,i;
        cin>>t>>x;
        if(t==1)
        {
            cin>>y;
            x--,y--;
            pr[x]=get(y);
            PAR[x]=y;
        }
        if(t==2)
        {
            x--;
            par[T]=get(x);
            ver[T]=x;
            T++;
        }
        if(t==3)
        {
            cin>>i;
            x--,i--;
            query TT;
            TT.parent=par[i];
            TT.vertex=x;
            TT.num=Z++;
            Q[ver[i]].push_back(TT);
        }
    }
    for(int i=0;i<n;i++) if(i!=get(i)) G[PAR[i]].push_back(i);
    for(int i=0;i<n;i++) if(i==get(i)) dfs(i,1);
    for(int i=0;i<Z;i++) cout<<(ans[i]?"YES":"NO")<<endl;
}