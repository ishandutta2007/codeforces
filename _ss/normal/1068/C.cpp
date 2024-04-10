#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e2+10;
int a[maxn][maxn*maxn],n,m;

void read()
{
    cin>>n>>m;
    int u,v;
    for (int i=1;i<=n;i++) a[i][(i-1)*n+1]=1;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v;
        if (u>v) swap(u,v);
        a[u][(v-1)*n+u]=1;
        a[v][(v-1)*n+u]=1;
    }
}

void process()
{
    vector<int> ans;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n*n;j++)
            if (a[i][j]) ans.pb(j);
        cout<<ans.size()<<endl;
        for (int j=0;j<ans.size();j++) cout<<i<<" "<<ans[j]<<endl;
        ans.clear();
    }
}

int main()
{
    read();
    process();
    return 0;
}