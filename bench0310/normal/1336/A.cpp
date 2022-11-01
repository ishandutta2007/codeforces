#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> p(N,0);
vector<int> depth(N,-1);
vector<int> sz(N,0);
void dfs(int a)
{
    depth[a]=depth[p[a]]+1;
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p[a]) continue;
        p[to]=a;
        dfs(to);
        sz[a]+=sz[to];
    }

}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    vector<int> cnt(n+1,0);
    cnt[1]=v[1].size();
    for(int i=2;i<=n;i++) cnt[i]=v[i].size()-1;
    priority_queue<array<int,2>> q;
    for(int i=1;i<=n;i++) if(cnt[i]==0) q.push({depth[i]-(sz[i]-1),i});
    ll res=0;
    while(k--)
    {
        auto [val,a]=q.top();
        q.pop();
        res+=val;
        cnt[p[a]]--;
        if(cnt[p[a]]==0) q.push({depth[p[a]]-(sz[p[a]]-1),p[a]});
    }
    printf("%I64d\n",res);
    return 0;
}