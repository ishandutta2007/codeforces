#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long ll;
template <class T>
using ordered_set=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

const int N=2005;
vector<int> v[N];
vector<int> sz(N,0);
vector<int> c(N,0);
ordered_set<int> s;
vector<int> res(N,0);

void dfs(int a)
{
    sz[a]=1;
    for(int to:v[a])
    {
        dfs(to);
        sz[a]+=sz[to];
    }
}

void solve(int a)
{
    int x=*s.find_by_order(c[a]);
    res[a]=x;
    s.erase(x);
    for(int to:v[a]) solve(to);
}

int main()
{
    int n;
    scanf("%d",&n);
    int root=0;
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d%d",&p,&c[i]);
        if(p==0) root=i;
        else v[p].push_back(i);
    }
    dfs(root);
    bool ok=1;
    for(int i=1;i<=n;i++) if(c[i]>sz[i]-1) ok=0;
    if(ok==0) printf("NO\n");
    else
    {
        for(int i=1;i<=n;i++) s.insert(i);
        solve(root);
        printf("YES\n");
        for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    }
    return 0;
}