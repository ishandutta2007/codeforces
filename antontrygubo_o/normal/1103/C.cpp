#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

vector<vector<int>> G;
vector<bool> visited;
vector<int> pr;
vector<int> depth;
vector<int> leaves;
int n, m, k;

void dfs(int start)
{
    visited[start] = true;
    bool kek = false;
    for (int i = 0; i<G[start].size(); i++) if (!visited[G[start][i]])
    {
        int t = G[start][i];
        pr[t] = start;
        depth[t] = depth[start] + 1;
        kek = true;
        dfs(t);
    }
    if (!kek) leaves.push_back(start);
}

void init_dfs(int start)
{
    pr[start] = -1;
    depth[start] = 1;
    dfs(start);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    G.resize(n+1);
    visited.resize(n+1);
    pr.resize(n+1);
    depth.resize(n+1);
    int a, b;
    for (int i = 0; i<m; i++) {cin>>a>>b; G[a].push_back(b); G[b].push_back(a);}
    init_dfs(1);
    for (int i = 1; i<=n; i++) if (depth[i]>=(n+k-1)/k)
    {
        cout<<"PATH"<<endl;
        cout<<depth[i]<<endl;
        cout<<i<<' '; while (i!=1) {i = pr[i]; cout<<i<<' ';}
        return 0;
    }
    cout<<"CYCLES"<<endl;
    for (int i = 0; i<k; i++)
    {
        int s = leaves[i];
        int idx = 0;
        while (G[s][idx]==pr[s]) idx++;
        int x = G[s][idx];
        idx = 0;
        while (G[s][idx]==pr[s]||G[s][idx]==x) idx++;
        int y = G[s][idx];
        if (depth[x]>depth[y]) swap(x, y);
        //cout<<s<<' '<<x<<' '<<y<<endl;
        int d = depth[s];
        if ((depth[s]-depth[y])%3!=2)
        {
            cout<<depth[s]-depth[y]+1<<endl;
            for (int j = 0; j<d-depth[y]+1; j++) {cout<<s<<' '; s = pr[s];}
            cout<<endl;
            continue;
        }
        if ((depth[s]-depth[x])%3!=2)
        {
            cout<<depth[s]-depth[x]+1<<endl;
            for (int j = 0; j<d-depth[x]+1; j++) {cout<<s<<' '; s = pr[s];}
            cout<<endl;
            continue;
        }
        cout<<depth[y]-depth[x]+2<<endl;
        cout<<s<<' ';
        s = y;
        for (int j = 0; j<depth[y]-depth[x]+1; j++) {cout<<s<<' '; s = pr[s];}
        cout<<endl;
    }

}