#include <bits/stdc++.h>

using namespace std;
const int N=200005;

int n;
vector<int> v[N];
vector<long long> sz(N,0);
long long res,now;

void dfs(int a,int p=-1)
{
    sz[a]++;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        sz[a]+=sz[to];
    }
    now+=sz[a];
}

void sw(int root,int a)
{
    now-=(sz[root]+sz[a]);
    sz[root]=(long long)n-sz[a];
    sz[a]=n;
    now+=(sz[root]+sz[a]);
    res=max(res,now);
}

void solve(int a,int p=-1)
{
    for(int to:v[a])
    {
        if(to==p) continue;
        sw(a,to);
        solve(to,a);
        sw(to,a);
    }
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    res=now;
    solve(1);
    printf("%I64d\n",res);
	return 0;
}