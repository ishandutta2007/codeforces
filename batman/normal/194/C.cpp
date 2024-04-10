#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (2600)
#define INF ((ll)1e9)

ll n,m,cnt,num,sub_d[N],d[N],root,cut[N],t;
char s[55][55];
bool mark[N],p,cycle;
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
    bool tmp=0;
    if(!t)cnt++;
    mark[x]=1;
    sub_d[x]=d[x];
    for(int i=0;i<e[x].size();i++)
    {
            if(mark[e[x][i]] && e[x][i]!=par)cycle=1;
            if(!mark[e[x][i]])
            {
                d[e[x][i]]=d[x]+1;
                dfs(e[x][i],x);
                sub_d[x]=min(sub_d[x],sub_d[e[x][i]]);
                if(sub_d[e[x][i]]>=d[x])
                    tmp=1;
            }
            else if(e[x][i]!=par)
                sub_d[x]=min(sub_d[x],d[e[x][i]]);
    }
    cut[x]+=tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>s[i][j];if(s[i][j]=='#')num++;}
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int p=-1;p<=1;p++)
                for(int q=-1;q<=1;q++)
                    if((!p ^ !q) && i+p>=0 && j+q>=0 && i+p<n && j+q<m && s[i][j]=='#' && s[i+p][j+q]=='#')
                        e[i*m+j].push_back((i+p)*m+j+q);                
    for(int i=0;i<n*m && t<2;i++)
        if(s[i/m][i%m]=='#')
        {
            for(int j=0;j<n*m;j++)mark[j]=d[j]=sub_d[j]=0;
            root=i;
            dfs(i);
            t++;
        }
    for(int i=0;i<n*m;i++)if(cut[i]==2)p=1;    
    if(p)cout<<1;
    else if(cnt!=num)cout<<0;
    else if(cycle)cout<<2;                      
    else cout<<-1;
    return 0;
}