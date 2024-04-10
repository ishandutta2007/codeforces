#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e5+5;

int n, ans=0;
int a[N], b[N], root[N], sz[N], sum[N], vis[N];

void init()
{
    for(int i=1;i<=n;i++)
    {
        root[i]=i;
        sz[i]=1;
        sum[i]=a[i];
    }
}

int rt(int k)
{
    while(k!=root[k])
    {
        root[k]=root[root[k]];
        k=root[k];
    }
    return k;
}

void merge(int u, int v)
{
    int rt1=rt(u);
    int rt2=rt(v);

    if(rt1==rt2)
        return;

    ans=max(ans, sum[rt1] + sum[rt2]);

    if(sz[rt2]>=sz[rt1])
    {
        sz[rt2]+=sz[rt1];
        sz[rt1]=0;
        root[rt1]=root[rt2];
        sum[rt2]+=sum[rt1];
    }
    else
    {
        sz[rt1]+=sz[rt2];
        sz[rt2]=0;
        root[rt2]=root[rt1];
        sum[rt1]+=sum[rt2];
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    init();
    reverse(b+1, b+n+1);
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        v.push_back(ans);
        vis[b[i]]=1;
        ans=max(ans, a[b[i]]);
        if(vis[b[i]-1])
            merge(b[i], b[i]-1);
        if(vis[b[i]+1])
            merge(b[i], b[i]+1);
    }
    reverse(v.begin(), v.end());
    for(auto it:v)
        cout<<it<<endl;
    return 0;
}