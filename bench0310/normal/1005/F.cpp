#include <bits/stdc++.h>

using namespace std;

const int N=200005;
int n,m,k;
vector<pair<int,int>> v[N];
vector<int> t;
vector<int> depth(N,-1);
vector<bool> now;
vector<vector<bool>> res;

void solve(int idx)
{
    if((int)res.size()==k) return;
    if(idx==n-1)
    {
        res.push_back(now);
        return;
    }
    int a=t[idx];
    for(pair<int,int> p:v[a])
    {
        int to=p.first;
        if(depth[to]==depth[a]-1)
        {
            now[p.second]=1;
            solve(idx+1);
            now[p.second]=0;
        }
    }
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    queue<int> q;
    q.push(1);
    depth[1]=0;
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        if(e!=1) t.push_back(e);
        for(pair<int,int> p:v[e])
        {
            int to=p.first;
            if(depth[to]!=-1) continue;
            depth[to]=depth[e]+1;
            q.push(to);
        }
    }
    now.resize(m,0);
    solve(0);
    printf("%d\n",(int)res.size());
    for(vector<bool> temp:res)
    {
        for(bool b:temp) printf("%d",b);
        printf("\n");
    }
	return 0;
}