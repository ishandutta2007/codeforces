#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> s;
vector<string> col;
vector<array<int,2>> now; //current dfs stack
vector<vector<int>> vis; //0-unvis 1-active 2-inactive
vector<vector<int>> cycle_id;
vector<vector<int>> cycle_sz;
vector<vector<int>> dist; //distance to origin node of its cycle
vector<int> h; //cycle_id -> cycle_sz
int idx=1;

array<int,2> nxt(array<int,2> a)
{
    if(s[a[0]][a[1]]=='U') return {a[0]-1,a[1]};
    else if(s[a[0]][a[1]]=='D') return {a[0]+1,a[1]};
    else if(s[a[0]][a[1]]=='L') return {a[0],a[1]-1};
    else return {a[0],a[1]+1};
}

void dfs(array<int,2> a)
{
    vis[a[0]][a[1]]=1;
    now.push_back(a);
    array<int,2> b=nxt(a);
    if(vis[b[0]][b[1]]==0) dfs(b);
    else if(vis[b[0]][b[1]]==1)
    {
        int sz=0;
        bool st=0;
        for(array<int,2> x:now)
        {
            if(x==b) st=1;
            if(st) sz++;
        }
        h[idx]=sz;
        dist[a[0]][a[1]]=0;
        cycle_id[a[0]][a[1]]=idx++;
        cycle_sz[a[0]][a[1]]=sz;
    }
    if(vis[b[0]][b[1]]!=1)
    {
        dist[a[0]][a[1]]=dist[b[0]][b[1]]+1;
        cycle_id[a[0]][a[1]]=cycle_id[b[0]][b[1]];
        cycle_sz[a[0]][a[1]]=cycle_sz[b[0]][b[1]];
    }
    vis[a[0]][a[1]]=2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        s.assign(n,string());
        col.assign(n,string());
        for(int o=0;o<n;o++)
        {
            cin >> col[o];
            for(int i=0;i<m;i++) col[o][i]=('0'+'1'-col[o][i]);
        }
        for(int o=0;o<n;o++) cin >> s[o];
        vis.assign(n,vector<int>(m,0));
        cycle_id.assign(n,vector<int>(m,0));
        cycle_sz.assign(n,vector<int>(m,0));
        dist.assign(n,vector<int>(m,0));
        h.assign(n*m+1,0);
        idx=1;
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                if(vis[o][i]==0)
                {
                    dfs({o,i});
                    now.clear();
                }
            }
        }
        vector<vector<int>> x;
        x.push_back(vector<int>());
        for(int i=1;i<idx;i++) x.push_back(vector<int>(h[i],-1));
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                x[cycle_id[o][i]][dist[o][i]%cycle_sz[o][i]]=max(x[cycle_id[o][i]][dist[o][i]%cycle_sz[o][i]],col[o][i]-'0');
            }
        }
        int res=0;
        int cnt=0;
        for(int i=1;i<idx;i++)
        {
            for(int j=0;j<(int)x[i].size();j++)
            {
                res+=(x[i][j]>=0);
                cnt+=(x[i][j]==1);
            }
        }
        cout << res << " " << cnt << "\n";
    }
    return 0;
}