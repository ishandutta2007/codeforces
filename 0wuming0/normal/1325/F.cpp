#include"bits/stdc++.h"
using namespace std;
int num,n,m;
int vis[100007];
map<int,bool>v[100007];
int save[100007],nn;
int ans[100007],ansnum=0;
void add(int k)
{
    ans[ansnum++]=k;
}
int ko(int now,int &t)
{
    int flag=1;
    for(map<int,bool>::iterator it=v[now].begin();it!=v[now].end();++it)
    {
        if(!it->second)continue;
        v[it->first][now]=0;
        if(vis[it->first]!=-1)
        {
            if(vis[now]-vis[it->first]+1>=num)
            {
                cout<<2<<endl<<vis[now]-vis[it->first]+1<<endl<<now;
                return it->first;
            }
            continue;
        }
        vis[it->first]=vis[now]+1;
        int bb,tt;
        if(bb=ko(it->first,tt))
        {
            cout<<" "<<now;
            if(bb==now)
            {
                cout<<endl;
                exit(0);
            }
            return bb;
        }
        if(flag)t=tt;
        else t=min(t,tt);
        flag=0;
    }
    if(flag)
    {
        t=vis[now];
        add(now);
    }
    if(t-num+1>=vis[now])
    {
        t=vis[now];
        add(now);
    }
    return 0;
}
void solve(int now)
{
    int t=1e9;
    vis[now]=0;
    ko(now,t);
}
int main()
{
    cin>>n>>m;
    for(num=1;num*num<n;num++);
    for(int i=0;i<100007;i++)vis[i]=-1;
    //cout<<num<<endl;
    while(m--)
    {
        int i,j;
        scanf("%d%d",&i,&j);
        v[i][j]=1;
        v[j][i]=1;
    }
    for(int i=1;i<=n;i++)if(vis[i]==-1)
        solve(i);
    cout<<1<<endl;
    for(int i=0;i<num;i++)printf("%d%c",ans[i]," \n"[i==num-1]);
    return 0;
}