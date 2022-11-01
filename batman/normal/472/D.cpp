#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (2222)

ll n,dis[N][N],dis_tmp,cnt;
pair <ll,ll> p[N];
vector <pair <ll,ll> > e[N];
bool mark[N];

void dfs(ll x,ll start)
{
    cnt++;
    mark[x]=1;
    if(dis_tmp!=dis[start][x]){cout<<"NO";exit(0);}
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i].first])
        {
            if(!e[x][i].second){cout<<"NO";exit(0);}
            dis_tmp+=e[x][i].second,dfs(e[x][i].first,start),dis_tmp-=e[x][i].second;
        }   
    mark[x]=0;      
}

void check()
{
    for(int i=0;i<n;i++)if(dis[i][i]!=0){cout<<"NO";exit(0);}
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(dis[i][j]!=dis[j][i]){cout<<"NO";exit(0);}
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&dis[i][j]);
    check();
    for(int i=0;i<n;i++)p[i]={dis[0][i],i};
    sort(p,p+n);
    
    vector <ll> id;
    id.push_back(0);
    for(int i=1;i<n;i++)
        for(int j=id.size()-1;j>=0;j--)
            if(dis[0][p[i].second]==dis[id[j]][0]+dis[id[j]][p[i].second])
            {
                id.push_back(p[i].second),e[p[i].second].push_back({id[j],dis[id[j]][p[i].second]}),e[id[j]].push_back({p[i].second,dis[id[j]][p[i].second]});
                break;
            }
    
    for(int i=0;i<n;i++)
    {
        cnt=0;
        dfs(i,i);
        if(cnt!=n){cout<<"NO";exit(0);}
    }
    cout<<"YES";
    return 0;
}