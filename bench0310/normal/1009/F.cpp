#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

int n;
const int N=1000005;
vector<int> v[N];
vector<int> sz(N);
vector<int> depth(N);
vector<pair<int,int>> best(N,make_pair(0,0));
vector<int> res(N);

void _dfs(int a,int p=-1)
{
    if(p!=-1) depth[a]=depth[p]+1;
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        _dfs(to,a);
        sz[a]+=sz[to];
    }
}

map<int,int> dfs(int a,int p=-1)
{
    map<int,int> m;
    int big=-1;
    for(int to:v[a]) if(to!=p&&(big==-1||sz[to]>sz[big])) big=to;
    if(big!=-1)
    {
        m=dfs(big,a);
        best[a]=best[big];
    }
    for(int to:v[a])
    {
        if(to==p||to==big) continue;
        map<int,int> t=dfs(to,a);
        for(pair<int,int> p:t)
        {
            m[p.first]+=p.second;
            if(m[p.first]>best[a].first||(m[p.first]==best[a].first&&p.first<best[a].second)) best[a]={m[p.first],p.first};
        }
    }
    m[depth[a]]++;
    if(m[depth[a]]>best[a].first||(m[depth[a]]==best[a].first&&depth[a]<best[a].second)) best[a]={m[depth[a]],depth[a]};
    res[a]=best[a].second-depth[a];
    //cout << "in " << a << " at depth " << depth[a] << endl;
    //for(pair<int,int> p:m) cout << p.second << " at depth " << p.first << endl;
    //cout << "best: " << best[a].first << " at depth " << best[a].second << endl;
    return m;
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
    _dfs(1);
    dfs(1);
    for(int i=1;i<=n;i++) printf("%d\n",res[i]);
	return 0;
}