#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
vector<int> depth(N,0);
vector<int> tin(N);
vector<int> tout(N);
vector<int> p(N);
int tcnt=1;

void dfs(int a)
{
    depth[a]=depth[p[a]]+1;
    tin[a]=tcnt++;
    for(int to:v[a])
    {
        if(to==p[a]) continue;
        p[to]=a;
        dfs(to);
    }
    tout[a]=tcnt-1;
}

bool sub(int a,int b)
{
    return (tin[a]<=tin[b]&&tin[b]<=tout[a]);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    p[1]=1;
    dfs(1);
    while(m--)
    {
        int k;
        scanf("%d",&k);
        vector<int> a(k);
        int x=1;
        for(int i=0;i<k;i++)
        {
            scanf("%d",&a[i]);
            if(depth[a[i]]>depth[x]) x=a[i];
        }
        bool ok=1;
        for(int y:a) if(sub(p[y],x)==0) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}