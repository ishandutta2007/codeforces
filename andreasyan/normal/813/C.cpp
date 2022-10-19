#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=200005;

int n,s;
vector<int> a[N];

int p[N],ss[N],h[N],d[N];
void dfs(int x,int pp)
{
    p[x]=pp;
    if(x==s)
        ss[x]=-1;
    h[x]=h[pp]+1;
    d[x]=h[x];
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(h==pp)
            continue;
        dfs(h,x);
        if(ss[h])
            ss[x]=h;
        d[x]=max(d[x],d[h]);
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("sweets.in","r",stdin);
    //freopen("sweets.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    int ans=0;
    int x=1,y=s;
    while(1)
    {
        ans=max(ans,(d[y]-1)*2);
        if(p[y]==x)
            break;
        y=p[y];
        if(ss[x]==y)
            break;
        x=ss[x];
    }
    cout<<ans<<endl;
    return 0;
}