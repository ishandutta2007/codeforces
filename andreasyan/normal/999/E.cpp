#include <bits/stdc++.h>
using namespace std;
const int N=5005;

int n,m,s;
vector<int> a[N],b[N];

int c[N];
vector<int> v;
void dfs(int x)
{
    c[x]=1;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(!c[h])
            dfs(h);
    }
    v.push_back(x);
}

int k;
void dfs1(int x)
{
    c[x]=k;
    for(int i=0;i<b[x].size();++i)
    {
        int h=b[x][i];
        if(!c[h])
            dfs1(h);
    }
}

bool mt[N];
int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
        if(!c[i])
            dfs(i);
    reverse(v.begin(),v.end());
    for(int i=1;i<=n;++i)
        c[i]=0;
    for(int j=0;j<n;++j)
    {
        int i=v[j];
        if(!c[i])
        {
            ++k;
            dfs1(i);
        }
    }
    for(int x=1;x<=n;++x)
    {
        for(int i=0;i<a[x].size();++i)
        {
            int y=a[x][i];
            if(c[x]!=c[y])
                mt[c[y]]=true;
        }
    }
    int ans=0;
    for(int i=1;i<=k;++i)
        if(!mt[i])
            ans++;
    if(!mt[c[s]])
        ans--;
    cout<<ans<<endl;
    return 0;
}