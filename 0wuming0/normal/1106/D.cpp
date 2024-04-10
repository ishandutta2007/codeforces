#include"bits/stdc++.h"
using namespace std;
map<int,int>mp;
int vis[100006];
vector<int> v[100006];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        v[p].push_back(q);
        v[q].push_back(p);
    }
    cout<<1;
    vis[1]=1;
    for(vector<int>::iterator it=v[1].begin();it!=v[1].end();it++)
    {
        if(!vis[*it])mp[*it]=1;
    }
    while(mp.size())
    {
        int t=mp.begin()->first;
        printf(" %d",t);
        vis[t]=1;
        mp.erase(mp.begin());
        for(vector<int>::iterator it=v[t].begin();it!=v[t].end();it++)
        {
            if(!vis[*it])mp[*it]=1;
        }
    }
    cout<<endl;
    return 0;
}