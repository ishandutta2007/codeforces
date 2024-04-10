#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
vector<int> sz(N);
vector<int> t;
vector<int> pos(N);

void dfs(int a)
{
    t.push_back(a);
    pos[a]=t.size()-1;
    sz[a]=1;
    for(int to:v[a])
    {
        dfs(to);
        sz[a]+=sz[to];
    }
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        v[p].push_back(i);
    }
    dfs(1);
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(b<=sz[a]) printf("%d\n",t[pos[a]+b-1]);
        else printf("-1\n");
    }
	return 0;
}