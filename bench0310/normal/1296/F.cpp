#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=5005;
vector<int> v[N];
vector<vector<int>> id(N,vector<int>(N,0));
vector<int> res(N,1);

vector<int> path(int x,int y)
{
    queue<int> q;
    vector<int> p(N,-1);
    q.push(x);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(p[to]==-1)
            {
                p[to]=a;
                q.push(to);
            }
        }
    }
    vector<int> b;
    while(y!=x)
    {
        b.push_back(id[y][p[y]]);
        y=p[y];
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        id[a][b]=id[b][a]=i;
    }
    int m;
    cin >> m;
    vector<array<int,3>> q(m);
    for(int i=0;i<m;i++)
    {
        int a,b,x;
        cin >> a >> b >> x;
        q[i]={a,b,x};
        vector<int> p=path(a,b);
        for(int z:p) res[z]=max(res[z],x);
    }
    bool ok=1;
    for(auto [a,b,x]:q)
    {
        vector<int> p=path(a,b);
        int y=1000000;
        for(int z:p) y=min(y,res[z]);
        ok&=(x==y);
    }
    if(ok) for(int i=1;i<=n-1;i++) cout << res[i] << " \n"[i==n-1];
    else cout << "-1\n";
    return 0;
}