#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using ld = long double;



#define mp make_pair

const int p = 998244353;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}


mt19937 rnd(time(0));


const int N = 1000005;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}




/*struct DSU
{
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

const int INF = 1000;

vector<vector<int>> G;

vector<int> color;

void dfs(int v, int col = 0)
{
    color[v] = col;
    for (auto it: G[v])
    {
        if (color[it]!=-1)
        {
            if (color[it]==col) {cout<<"NO"; exit(0);}
        }
        else dfs(it, 1-col);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> fixed, free;
    for (int i = 0; i<m; i++)
    {
        int u, v, b;
        cin>>u>>v>>b;
        u--; v--;
        if (b==1) fixed.push_back(mp(u, v)); else free.push_back(mp(u, v));
    }

    G.resize(n);
    for (auto it: fixed)
    {
        G[it.first].push_back(it.second);
        G[it.second].push_back(it.first);
    }
    for (auto it: free)
    {
        G[it.first].push_back(it.second);
        G[it.second].push_back(it.first);
    }

    color = vector<int>(n, -1);
    dfs(0);

    //for (auto it: color) cout<<it<<' ';

    vector<vector<int>> d(n, vector<int>(n, INF));

    for (int i = 0; i<n; i++) d[i][i] = 0;
    for (auto it: fixed)
    {
        d[it.first][it.second] = 1;
        d[it.second][it.first] = -1;
    }
    for (auto it: free)
    {
        d[it.first][it.second] = 1;
        d[it.second][it.first] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 0; i<n; i++) if (d[i][i]<0) {cout<<"NO"; exit(0);}

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            //cout<<i<<' '<<j<<": "<<d[i][j]<<endl;
        }

    cout<<"YES"<<endl;
    int l = -1; int r = -1; int maxx = -1000;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++) if (d[i][j]>maxx)
            {
                maxx = d[i][j]; l = i; r = j;
            }
    cout<<maxx<<endl;

    for (int i = 0; i<n; i++) cout<<d[l][i]<<' ';


}