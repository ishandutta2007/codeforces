#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
vector<int> g[N];
vector<int> gr[N];

vector<bool> vis(N);
vector<int> order,component;

void dfs1(int a)
{
    vis[a]=1;
    for(int to:g[a]) if(vis[to]==0) dfs1(to);
    order.push_back(a);
}

void dfs2(int a)
{
    vis[a]=1;
    component.push_back(a);
    for(int to:gr[a]) if(vis[to]==0) dfs2(to);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            gr[b].push_back(a);
        }
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++) if(vis[i]==0) dfs1(i);
        for(int i=1;i<=n;i++) vis[i]=0;
        dfs2(order.back());
        if((int)component.size()==n) printf("No\n");
        else
        {
            printf("Yes\n");
            printf("%d %d\n",n-(int)component.size(),(int)component.size());
            vector<bool> cats(n+1,0);
            for(int cat:component) cats[cat]=1;
            for(int i=1;i<=n;i++) if(cats[i]==0) printf("%d ",i);
            printf("\n");
            for(int cat:component) printf("%d ",cat);
            printf("\n");
        }
        order.clear();
        component.clear();
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            gr[i].clear();
        }
    }
	return 0;
}