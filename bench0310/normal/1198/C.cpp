#include <bits/stdc++.h>

using namespace std;

int n,m;
const int N=300005;
vector<int> v[N];
vector<int> deg(N,0);
vector<pair<int,int>> edges;

vector<int> matching()
{
    vector<int> res;
    vector<pair<int,int>> t;
    for(int i=0;i<m;i++) t.push_back({deg[edges[i].first]+deg[edges[i].second],i});
    sort(t.begin(),t.end());
    vector<bool> vis(3*n+1,0);
    for(int i=0;i<m;i++)
    {
        if((int)res.size()==n) break;
        int a=edges[t[i].second].first;
        int b=edges[t[i].second].second;
        if(vis[a]||vis[b]) continue;
        vis[a]=1;
        vis[b]=1;
        res.push_back(t[i].second+1);
    }
    return res;
}

vector<int> indset()
{
    vector<int> res;
    vector<pair<int,int>> t;
    for(int i=1;i<=3*n;i++) t.push_back({deg[i],i});
    sort(t.begin(),t.end());
    vector<bool> vis(3*n+1,0);
    for(int i=0;i<3*n;i++)
    {
        if((int)res.size()==n) break;
        int a=t[i].second;
        if(vis[a]) continue;
        res.push_back(a);
        vis[a]=1;
        for(int to:v[a]) vis[to]=1;
    }
    return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            edges.push_back({a,b});
            v[a].push_back(b);
            v[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        vector<int> one=matching();
        vector<int> two=indset();
        if((int)one.size()==n)
        {
            printf("Matching\n");
            for(int a:one) printf("%d ",a);
            printf("\n");
        }
        else if((int)two.size()==n)
        {
            printf("IndSet\n");
            for(int a:two) printf("%d ",a);
            printf("\n");
        }
        else printf("Impossible\n");
        for(int i=1;i<=3*n;i++)
        {
            deg[i]=0;
            v[i].clear();
        }
        edges.clear();
    }
	return 0;
}