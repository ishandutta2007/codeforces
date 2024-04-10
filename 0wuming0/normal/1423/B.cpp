#include"bits/stdc++.h"
using namespace std;
int uu[100005],vv[100005],d[100005];
int n,m;
vector<int>v[20005];
int num[20005];
int vis[20005];
bool ans=1;
void solve(int i)
{
    if(vis[i])return;
    vis[i]=1;
    for(auto j:v[i])if(vis[j]==0)
    {
        vis[j]=1;
        for(auto k:v[j])if(vis[k]==0)
        {
            num[k]--;
            if(num[k]==1)
            {
                solve(k);
            }
            else if(num[j]==0)
            {
                ans=0;
            }
        }
    }
}
int check(int i)
{
    vis[i]=2;
    int ans=0;
    if(i<=n)ans--;
    else ans++;
    for(auto j:v[i])if(vis[j]==0)
    {
        ans+=check(j);
    }
    return ans;
}
bool judge(int x)
{
    for(int i=0;i<20005;i++)v[i].clear();
    for(int i=0;i<m;i++)
    {
        if(d[i]<=x)
        {
            v[uu[i]].push_back(vv[i]);
            v[vv[i]].push_back(uu[i]);
        }
    }
    ans=1;
    for(int i=0;i<20005;i++)
    {
        num[i]=v[i].size();
        vis[i]=0;
    }
    for(int i=1;i<=2*n;i++)if(vis[i]==0)
    {
        if(num[i]==1)
        {
            solve(i);
        }
        else if(num[i]==0)
        {
            return false;
        }
    }
    for(int i=1;i<=2*n;i++)if(vis[i]==0)
    {
        if(check(i))return false;
    }
    return true;
}
map<pair<int,int>,int>mp;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        pair<int,int>pr;
        pr.first=u;
        pr.second=v;
        if(mp.find(pr)==mp.end())mp[pr]=d;
        else mp[pr]=min(mp[pr],d);
    }
    m=0;
    for(auto pr:mp)
    {
        uu[m]=pr.first.first;
        vv[m]=pr.first.second+n;
        d[m++]=pr.second;
    }/*
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",uu+i,vv+i,d+i);
        vv[i]+=n;
    }*/
    int x,x1=0,x2=1e9+7;
    while(x1+1!=x2)
    {//cout<<x1<<" "<<x2<<endl;
        x=x1+x2;
        x/=2;
        if(judge(x))x2=x;
        else x1=x;
    }
    if(x2==1e9+7)x2=-1;
    cout<<x2<<endl;
    return 0;
}
/*
3 7
1 2 1
2 3 2
3 3 3
2 1 4
2 2 5
2 1 100
1 2 100

7 16
1 1 1
1 2 1
2 2 1
2 1 1
2 3 1
2 4 1
3 3 1
3 4 1
4 5 1
5 5 1
4 6 1
5 6 1
6 6 1
7 6 1
6 7 1
7 7 1
*/