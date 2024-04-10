#include"bits/stdc++.h"
#define ll long long
using namespace std;
int f[100];
map<int,int>mp[200005];
int pr[200005],vis[200005];
int getvis[200005],getnum;
void add(vector<int>&pos,int v)
{
    getvis[v]=getnum;
    pos.push_back(v);
    for(map<int,int>::iterator it=mp[v].begin();it!=mp[v].end();it++)
    {
        if(getvis[it->first]!=getnum)
        {
            add(pos,it->first);
        }
    }
}
int get(int i)
{
    vis[i]=1;
    //map<int,int>::iterator it0=vis.find(i);
    for(map<int,int>::iterator it=mp[i].begin();it!=mp[i].end();it++)
    {
        if(vis[it->first]==0)
        {
            pr[it->first]=i;
            int qq=get(it->first);
            vis[i]+=qq;
        }
    }//cout<<"<<<"<<i<<" "<<vis[i]<<" "<<pr[i]<<endl;
    return vis[i];
}
int solve(int v,int now)
{//cout<<"!!!!"<<v<<" "<<now<<endl;
    if(now<=3)return 1;
    vector<int>point;
    getnum++;
    add(point,v);
    int t=f[now-2];
    int tt=f[now-1];
    int n=f[now];
    for(vector<int>::iterator it=point.begin();it!=point.end();it++)
    {//cout<<*it<<" "<<vis[*it]<<endl;
        if(vis[*it]==t)
        {
            mp[*it].erase(mp[*it].find(pr[*it]));
            mp[pr[*it]].erase(mp[pr[*it]].find(*it));
            int kk=pr[*it];
            while(1)
            {
                vis[kk]-=t;
                if(kk==v)break;
                kk=pr[kk];
            }
            if(solve(v,now-1)==1&&solve(*it,now-2)==1)
            {
                return 1;
            }
            else return 0;
        }
        #define t tt
        if(vis[*it]==t)
        {
            mp[*it].erase(mp[*it].find(pr[*it]));
            mp[pr[*it]].erase(mp[pr[*it]].find(*it));
            int kk=pr[*it];
            while(1)
            {
                vis[kk]-=t;
                if(kk==v)break;
                kk=pr[kk];
            }
            if(solve(v,now-2)==1&&solve(*it,now-1)==1)
            {
                return 1;
            }
            else return 0;
        }
        #undef t
    }
    return 0;
}
int main()
{
    int n;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<30;i++)
    {
        f[i]=f[i-1]+f[i-2];
        //cout<<f[i]<<endl;
    }
    cin>>n;
    int now=0;
    for(int i=1;i<30;i++)
    {
        if(f[i]==n)
        {
            now=i;break;
        }
    }
    if(now==0)
    {cout<<"no"<<endl;
    return 0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        mp[u][v]=1;
        mp[v][u]=1;
    }
    get(1);
    if(solve(1,now))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
/*
13
1 2
1 3
1 4
3 5
2 6
6 7
7 8
9 1
10 1
11 3
12 9
13 7

13
8 2
8 3
8 4
3 5
2 6
6 7
7 1
9 8
10 8
11 3
12 9
13 7
*/