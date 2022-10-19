#include"bits/stdc++.h"
using namespace std;
#define ll long long
int last[100005];
ll d[100005];
int vis[100005];
vector<pair<int,int> >v[100005];
void pr(int i)
{//cout<<"<<"<<i<<endl;
    if(i==1)
    {
        cout<<i;
        return;
    }
    pr(last[i]);
    cout<<" "<<i;
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(pair<int,int>(b,c));
        v[b].push_back(pair<int,int>(a,c));
    }
    for(int i=1;i<=n;i++)d[i]=1e18;
    multimap<ll,int>mp;
    mp.insert(pair<ll,int>(0,1));
    d[1]=0;
    while(mp.size())
    {
        auto x=mp.begin()->first;
        auto y=mp.begin()->second;
        mp.erase(mp.begin());
        if(vis[y]==0)
        {
            vis[y]=1;
            for(auto pr:v[y])
            {
                if(x+pr.second<d[pr.first])
                {
                    d[pr.first]=x+pr.second;
                    last[pr.first]=y;
                }
                mp.insert(pair<ll,int>(x+pr.second,pr.first));
            }
        }
    }
    if(d[n]==1e18)cout<<-1<<endl;
    else
    {
        pr(n);
        cout<<endl;
    }
    return 0;
}