#include <bits/stdc++.h>
using namespace std;
const int N=200005,INF=999999999;

int n,m;
int sumb;
int a[N],b[N];

int ind[N];
vector<int> t[N];

int main()
{
    //freopen("dp.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ind[i]=t[a[i]].size()+1;
        t[a[i]].push_back(i);
    }
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
        sumb+=b[i];
    }
    int ans=INF;
    int z=0;
    for(int i=1;i<=m;++i)
        if(!b[i])
            ++z;
    set<int> s;
    for(int i=1;i<=n;++i)
    {
        if(b[a[i]])
        {
        if(ind[i]==b[a[i]])
        {
            ++z;
            s.insert(t[a[i]][ind[i]-b[a[i]]]);
        }
        else if(ind[i]>b[a[i]])
        {
            s.erase(t[a[i]][ind[i]-b[a[i]]-1]);
            s.insert(t[a[i]][ind[i]-b[a[i]]]);
        }
        }
        if(z==m)
            ans=min(ans,(i-*s.begin()+1)-sumb);
    }
    if(ans==INF)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}