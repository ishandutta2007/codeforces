#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll dis[606][606];
vector<pair<int,int> >v[606];
int n,m;
int ans[606][606];
int ans2[606][606];
int vis[606];
int last;
ll dis2[606][606];
int bestdis[606];
multiset<pair<ll,int> >st;
void solve2(int i,ll noww)
{
    if(vis[i]==1)return;
    vis[i]=1;
    for(auto pr:v[i])
    {
        if(noww+pr.second<=dis2[last][pr.first])
        {
            ans[pr.first][i]=ans[i][pr.first]=1;
        }
        pair<ll,int>p;
        p.first=noww+pr.second;
        p.second=pr.first;
        st.insert(p);
    }
}
int solve(int bg)
{
    last=bg;
    for(int i=0;i<=n;i++)vis[i]=0;
    pair<ll,int>p;
    p.first=0;
    p.second=bg;
    st.insert(p);
    while(st.size())
    {
        auto fi=(st.begin())->first;
        auto se=(st.begin())->second;
        st.erase(st.begin());
        solve2(se,fi);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        dis[i][j]=1e18;dis2[i][j]=-1;
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;for(int i=1;i<=n;i++)dis2[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        pair<int,int>pr;
        pr.first=b;
        pr.second=c;
        v[a].push_back(pr);
        pr.first=a;
        v[b].push_back(pr);
        dis[a][b]=dis[b][a]=c;
        ans2[a][b]=ans2[b][a]=1;
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dis2[a][b]=dis2[b][a]=max((ll)c,dis2[a][b]);
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        dis2[i][j]=dis2[j][i]=max(dis2[i][j],max(dis2[i][k]-dis[k][j],dis2[j][k]-dis[k][i]));
    }
    int sum=0;
    //for(int i=1;i<=n;i++)solve(i);
    /*
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%lld%c",dis[i][j]," \n"[j==n]);
    cout<<"!!!"<<endl;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%lld%c",dis2[i][j]," \n"[j==n]);//*/
    for(int i=1;i<=n;i++)for(auto pr:v[i])if(pr.second<=dis2[pr.first][i])sum++;
    cout<<sum/2<<endl;
    return 0;
}