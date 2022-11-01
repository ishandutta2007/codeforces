#include <bits/stdc++.h>
#define sz(a) ((int) a.size())
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int INF=(int)1e9;
const int N=3000;
int n, m, d[N][N], rd[N][N];
vector<int> kid1[N], kid2[N];
pii bo3[N][3], rbo3[N][3];

void go(vector<int> kid[], int ar[][N])
{
    for(int i=0; i<n; i++)
    {
        vector<bool> vis(n,0);
        vis[i]=1;
        queue<pii> q;
        q.push({i,0});
        while(!q.empty())
        {
            pii cur=q.front();
            q.pop();
            ar[i][cur.ff]=cur.ss;
            for(int j=0,sz=sz(kid[cur.ff]); j<sz; j++)
                if(!vis[kid[cur.ff][j]])
                {
                    vis[kid[cur.ff][j]]=1;
                    q.push({kid[cur.ff][j],cur.ss+1});
                }
        }
        for(int j=0; j<n; j++)
            if(ar[i][j]==INF)
                ar[i][j]=-1;
    }
}

bool check(int a, int b, int c, int d)
{
    return (a!=b&&a!=c&&a!=d&&b!=d&&c!=d&&a!=-1&&b!=-1&&c!=-1&&d!=-1);
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) { d[i][j]=INF; rd[i][j]=INF; }
    for(int i=0,u,v; i<m; i++) { cin>>u>>v; u--; v--; kid1[u].pb(v); kid2[v].pb(u); }
    for(int i=0; i<n; i++) { bo3[i][0]={-1,-1}; bo3[i][1]={-1,-1}; bo3[i][2]={-1,-1}; }
    for(int i=0; i<n; i++) { rbo3[i][0]={-1,-1}; rbo3[i][1]={-1,-1}; rbo3[i][2]={-1,-1}; }
    go(kid1, d); go(kid2, rd);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(d[i][j]>bo3[i][0].ff) { bo3[i][2]=bo3[i][1]; bo3[i][1]=bo3[i][0]; bo3[i][0]={d[i][j],j}; }
            else if(d[i][j]>bo3[i][1].ff) { bo3[i][2]=bo3[i][1]; bo3[i][1]={d[i][j],j}; }
            else if(d[i][j]>bo3[i][2].ff) { bo3[i][2]={d[i][j],j}; }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(rd[i][j]>rbo3[i][0].ff) { rbo3[i][2]=rbo3[i][1]; rbo3[i][1]=rbo3[i][0]; rbo3[i][0]={rd[i][j],j}; }
            else if(rd[i][j]>rbo3[i][1].ff) { rbo3[i][2]=rbo3[i][1]; rbo3[i][1]={rd[i][j],j}; }
            else if(rd[i][j]>rbo3[i][2].ff) { rbo3[i][2]={rd[i][j],j}; }

    int opt=-1, opta, optb, optc, optd;

    for(int b=0; b<n; b++)
        for(int c=0; c<n; c++)
            if(b!=c&&d[b][c]!=-1)
                for(int i=0; i<3; i++)
                    for(int j=0; j<3; j++)
                        if(check(rbo3[b][i].ss,b,c,bo3[c][j].ss)&&
                           opt<rbo3[b][i].ff+d[b][c]+bo3[c][j].ff)
                                {
                                    opt=rbo3[b][i].ff+d[b][c]+bo3[c][j].ff;
                                    opta=rbo3[b][i].ss;
                                    optb=b;
                                    optc=c;
                                    optd=bo3[c][j].ss;
                                }

    cout<<opta+1<<' '<<optb+1<<' ' <<optc+1<<' '<<optd+1;
    return 0;
}