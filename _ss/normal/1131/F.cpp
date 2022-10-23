#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=15e4+1;
int n,color[maxn],u,v;
vector<int> a[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    //freopen("ss.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        a[i].push_back(i);
        color[i]=i;
    }
    int x,y,t,h;
    //for (int i=1;i<=n;i++) cout<<color[i]<<" "; cout<<endl;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        t=color[u];
        h=color[v];
        x=a[t].size();
        y=a[h].size();
        if (x>y)
        {
            for (int j=0;j<y;j++)
            {
                color[a[h][j]]=t;
                a[t].push_back(a[h][j]);
            }
            a[h].empty();
            //for (int i=0;i<a[color[u]].size();i++) cout<<a[color[u]][i]<<" ";
            //cout<<endl;
        }
        else
        {
            for (int j=0;j<x;j++)
            {
                color[a[t][j]]=h;
                a[h].push_back(a[t][j]);
            }
            a[t].empty();
            //for (int i=0;i<a[color[v]].size();i++) cout<<a[color[v]][i]<<" ";
            //cout<<endl;
        }
    }
    for (int i=0;i<a[color[1]].size();i++) cout<<a[color[1]][i]<<" ";
    return 0;
}