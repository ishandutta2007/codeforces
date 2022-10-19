#include"bits/stdc++.h"
using namespace std;
struct rd
{
    int w;
    int pos;
};
set<pair<int,pair<int,int> > >mp;
vector<rd>v[100005];
int dp[100005][51];
int vis[100005];
void solve(int fee,int pos,int stute)
{
    pair<int,pair<int,int> >pr;
    pr.first=0;pr.second.first=1;pr.second.second=0;
    if(stute==0)
    {
        for(vector<rd>::iterator it=v[pos].begin();it!=v[pos].end();++it)
        {
            int fi;
            fi=fee;
            pr.second.first=it->pos;
            pr.second.second=it->w;
            if(fi<dp[pr.second.first][pr.second.second])
            {
                pr.first=dp[pr.second.first][pr.second.second];
                set<pair<int,pair<int,int> > >::iterator it=mp.find(pr);
                if(it!=mp.end())mp.erase(it);
                dp[pr.second.first][pr.second.second]=pr.first=fi;
                mp.insert(pr);
            }
        }
    }
    else
    {
        for(vector<rd>::iterator it=v[pos].begin();it!=v[pos].end();++it)
        {
            int fi;
            fi=fee+(stute+it->w)*(stute+it->w);
            pr.second.first=it->pos;
            pr.second.second=0;
            if(fi<dp[pr.second.first][pr.second.second])
            {
                pr.first=dp[pr.second.first][pr.second.second];
                set<pair<int,pair<int,int> > >::iterator it=mp.find(pr);
                if(it!=mp.end())mp.erase(it);
                dp[pr.second.first][pr.second.second]=pr.first=fi;
                mp.insert(pr);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,t,x;
        scanf("%d%d%d",&s,&t,&x);
        rd it;
        it.w=x;
        it.pos=s;
        v[t].push_back(it);
        it.pos=t;
        v[s].push_back(it);
    }
    for(int i=0;i<=n;i++)for(int j=0;j<=50;j++)dp[i][j]=2e9;
    dp[1][0]=0;
    pair<int,pair<int,int> >pr;
    pr.first=0;pr.second.first=1;pr.second.second=0;
    mp.insert(pr);
    while(mp.size())
    {
        set<pair<int,pair<int,int> > >::iterator it=mp.begin();
        int fi=it->first;pair<int,int> se=it->second;
        mp.erase(it);
        solve(fi,se.first,se.second);//cout<<fi<<" "<<se<<endl;
    }
    for(int i=1;i<=n;i++)if(dp[i][0]==2e9)dp[i][0]=-1;
    for(int i=1;i<=n;i++)printf("%d%c",dp[i][0]," \n"[i==n]);
    return 0;
}
/*
#include"bits/stdc++.h"
using namespace std;
struct rd
{
    int w;
    int pos;
};
set<pair<int,int> >mp;
vector<rd>v[100005];
int dp[100005];
int vis[100005];
void solve(int fee,int pos)
{
    pair<int,int>pr;
    for(vector<rd>::iterator it=v[pos].begin();it!=v[pos].end();++it)
    {
        for(vector<rd>::iterator it2=v[it->pos].begin();it2!=v[it->pos].end();++it2)
        {
            int a=(it->w+it2->w);
            int fi;
            fi=a*a+fee;
            pr.second=it2->pos;
            if(fi<dp[pr.second])
            {
                pr.first=dp[pr.second];
                set<pair<int,int> >::iterator it=mp.find(pr);
                if(it!=mp.end())mp.erase(it);
                dp[pr.second]=pr.first=fi;
                mp.insert(pr);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,t,x;
        scanf("%d%d%d",&s,&t,&x);
        rd it;
        it.w=x;
        it.pos=s;
        v[t].push_back(it);
        it.pos=t;
        v[s].push_back(it);
    }
    for(int i=0;i<=n;i++)dp[i]=2e9;
    dp[1]=0;
    pair<int,int>pr;
    pr.first=0;pr.second=1;
    mp.insert(pr);
    while(mp.size())
    {
        set<pair<int,int> >::iterator it=mp.begin();
        int fi=it->first,se=it->second;
        mp.erase(it);
        solve(fi,se);//cout<<fi<<" "<<se<<endl;
    }
    for(int i=1;i<=n;i++)if(dp[i]==2e9)dp[i]=-1;
    for(int i=1;i<=n;i++)printf("%d%c",dp[i]," \n"[i==n]);
    return 0;
}*/