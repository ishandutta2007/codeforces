#include<bits/stdc++.h>
using namespace std;
#define ll int
#define N (1111)

ll n,m,d[3][N][N];
string s[N];

void calc(ll i,ll j)
{
    ll p=s[i][j]-'1';
    queue <pair <ll,ll> > q[2];
                d[p][i][j]=1;
                q[0].push({i,j});
                while(q[0].size() || q[1].size())
                {
                    while(q[0].size())
                    {
                        ll x=q[0].front().first,y=q[0].front().second;
                        q[0].pop();
                        if(x>0 && d[p][x-1][y]==-1 && s[x-1][y]!='#')d[p][x-1][y]=d[p][x][y]+(s[x-1][y]=='.'),q[(s[x-1][y]=='.')].push({x-1,y});
                        if(y>0 && d[p][x][y-1]==-1 && s[x][y-1]!='#')d[p][x][y-1]=d[p][x][y]+(s[x][y-1]=='.'),q[(s[x][y-1]=='.')].push({x,y-1});
                        if(x<n-1 && d[p][x+1][y]==-1 && s[x+1][y]!='#')d[p][x+1][y]=d[p][x][y]+(s[x+1][y]=='.'),q[(s[x+1][y]=='.')].push({x+1,y});
                        if(y<m-1 && d[p][x][y+1]==-1 && s[x][y+1]!='#')d[p][x][y+1]=d[p][x][y]+(s[x][y+1]=='.'),q[(s[x][y+1]=='.')].push({x,y+1});
                    }
                    while(q[1].size())
                    {
                        ll x=q[1].front().first,y=q[1].front().second;
                        q[1].pop();
                        if(x>0 && d[p][x-1][y]==-1 && s[x-1][y]!='#')d[p][x-1][y]=d[p][x][y]+(s[x-1][y]=='.'),q[(s[x-1][y]!='.')].push({x-1,y});
                        if(y>0 && d[p][x][y-1]==-1 && s[x][y-1]!='#')d[p][x][y-1]=d[p][x][y]+(s[x][y-1]=='.'),q[(s[x][y-1]!='.')].push({x,y-1});
                        if(x<n-1 && d[p][x+1][y]==-1 && s[x+1][y]!='#')d[p][x+1][y]=d[p][x][y]+(s[x+1][y]=='.'),q[(s[x+1][y]!='.')].push({x+1,y});
                        if(y<m-1 && d[p][x][y+1]==-1 && s[x][y+1]!='#')d[p][x][y+1]=d[p][x][y]+(s[x][y+1]=='.'),q[(s[x][y+1]!='.')].push({x,y+1});
                    }
                }
}

int main()
{
    ios_base::sync_with_stdio();cin.tie();cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)d[0][i][j]=d[1][i][j]=d[2][i][j]=-1;
    bool mark[3]={};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]!='.' && s[i][j]!='#' && !mark[s[i][j]-'1'])
            {
                calc(i,j);
                mark[s[i][j]-'1']=1;
            }
    ll ans=(ll)1e9;     
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(d[0][i][j]!=-1 && d[1][i][j]!=-1 && d[2][i][j]!=-1)
                ans=min(ans,d[0][i][j]+d[1][i][j]+d[2][i][j]-3-((s[i][j]=='.')?2:0));//cout<<d[0][i][j]<<" "<<d[1][i][j]<<" "<<d[2][i][j]<<"\n";
    if(ans==(ll)1e9)return cout<<-1,0;          
    cout<<ans;          
    return 0;
}