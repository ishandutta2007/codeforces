#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair
/*
int p =  1e9 + 7;

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

int po(int a, ll deg)
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
*/

mt19937 rnd(time(0));

/*
const int N = 2000005;

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
}*/


struct DSU
{
    vector<int> sz;
    vector<int> parent;
    vector<bool> cycle;
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
        if (a==b) cycle[a] = true;
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            if (cycle[b]) cycle[a] = true;
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        cycle.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};

vector<set<int>> G;
vector<vector<int>> G1;
vector<bool> visited;

vector<int> parent;
vector<set<int>> children;
vector<int> depth;
set<pair<int, int>> order;

void dfs(int v, int par = -1)
{
    visited[v] = true;
    for (auto it: G1[v]) if (it!=par)
    {
        depth[it] = depth[v] + 1;
        order.insert(mp(depth[it], it));
        parent[it] = v; children[v].insert(it);
        dfs(it, v);
    }
}

vector<vector<int>> answers;

void process(int v)
{
    depth[v] = 0;
    order.insert(mp(0, v));
    parent[v] = -1;
    dfs(v);

    while (order.size())
    {
        auto it = *prev(order.end());
        int par = parent[it.second];
        vector<int> star = {par};
        order.erase(mp(depth[par], par));
        if (par!=v) children[parent[par]].erase(par);
        for (auto child: children[par])
        {
            order.erase(mp(depth[child], child));
            star.push_back(child);
        }
        if (order.size()==1)
        {
            star.push_back(v); order.clear();
        }
        answers.push_back(star);
    }
}



void solve()
{
    int n, m;
    cin>>n>>m;

    G.clear(); G.resize(n);
    for (int i = 0; i<m; i++)
    {
        int l, r; cin>>l>>r; l--; r--; G[l].insert(r); G[r].insert(l);
    }

    vector<int> adj(n, -1);
    for (int i = 0; i<n; i++)
    {
        if (G[i].size()<n-1)
        {
            for (int j = 0; j<n; j++) if (j!=i && G[i].count(j)==0)
            {
                adj[i] = j;
                break;
            }
        }
    }
    G1.clear(); G1.resize(n);

    /*for (auto it: adj) cout<<it<<' ';
    cout<<endl;*/

    DSU dsu(n);
    //cout<<"EGDES"<<endl;
    for (int i = 0; i<n; i++) if (adj[i]!=-1 && dsu.find_set(i)!=dsu.find_set(adj[i]))
    {
        G1[i].push_back(adj[i]); G1[adj[i]].push_back(i);
        dsu.union_sets(adj[i], i);
        //cout<<i<<' '<<adj[i]<<endl;
    }
    //cout<<endl;

    children.clear(); children.resize(n);
    parent.clear(); parent.resize(n);
    visited.clear(); visited.resize(n);
    depth.clear(); depth.resize(n); order.clear();

    answers.clear();


    for (int i = 0; i<n; i++) if (!visited[i])
    {
        if (G1[i].size()==0) answers.push_back({i});
        else process(i);
    }

    /*for (auto vec: answers)
    {
        cout<<vec.size()<<endl;
        for (auto it: vec) cout<<it<<' ';
        cout<<endl;
    }*/



    vector<int> p(n), q(n);
    int cur = 1;
    for (auto vec: answers)
    {
        if (vec.size()==1)
        {
            p[vec[0]] = cur; q[vec[0]] = cur; cur++;
        }
        else
        {
            int k = vec.size();
            for (int i = 0; i<k; i++) p[vec[i]] = cur+i;
            for (int i = 0; i<k; i++) q[vec[i]] = cur+(i+k-1)%k;
            cur+=k;
        }
    }

    for (auto it: p) cout<<it<<' ';
    cout<<'\n';
    for (auto it: q) cout<<it<<' ';
    cout<<'\n';




}

/*
1
4 2
1 2
3 4
 */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();
}