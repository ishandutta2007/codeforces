#include"bits/stdc++.h"
using namespace std;
vector<int>v[300005];
int vis[300005];
struct qs
{
    int nowl,nowr;
    vector<int>l,r;
}que[300005];
int pr[300005];
int ok[300005];
multimap<int,int>mp;
void solve(int i)
{
    while(1)
    {
        auto it=mp.find(i);
        if(it==mp.end())break;
        int id=it->second;
        mp.erase(it);
        if(ok[id])continue;//cout<<"<<"<<id<<" "<<i<<" "<<pr[i]<<endl;
        if(que[id].nowl==i)
        {
            que[id].l.push_back(pr[i]);
            que[id].nowl=pr[i];
            if(que[id].nowr==pr[i])
            {
                ok[id]=1;
            }
            else
            {
                mp.insert(make_pair(pr[i],id));
            }
        }
        else
        {
            que[id].r.push_back(pr[i]);
            que[id].nowr=pr[i];
            if(que[id].nowl==pr[i])
            {
                ok[id]=1;
            }
            else
            {
                mp.insert(make_pair(pr[i],id));
            }
        }
    }
}
void dfs(int i)
{
    vis[i]=1;
    for(auto j:v[i])if(vis[j]==0)
    {
        pr[j]=i;
        dfs(j);
    }
    solve(i);
}
int num[300005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&que[i].nowl,&que[i].nowr);
        mp.insert(make_pair(que[i].nowl,i));
        mp.insert(make_pair(que[i].nowr,i));
        num[que[i].nowl]^=1;
        num[que[i].nowr]^=1;
        que[i].l.push_back(que[i].nowl);
        que[i].r.push_back(que[i].nowr);
    }
    {
        int s=0;
        for(int i=1;i<=n;i++)s+=num[i];
        if(s)
        {
            cout<<"NO"<<endl;
            cout<<s/2<<endl;
            return 0;
        }
    }
    dfs(1);
    cout<<"YES"<<endl;
    for(int i=1;i<=q;i++)
    {
        for(int j=que[i].r.size()-2;j>=0;j--)que[i].l.push_back(que[i].r[j]);
        cout<<que[i].l.size()<<endl;
        for(int j=0;j<que[i].l.size();j++)printf("%d%c",que[i].l[j]," \n"[j==que[i].l.size()-1]);
    }
    return 0;
}