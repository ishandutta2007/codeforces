#include <bits/stdc++.h>

using namespace std;

/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

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

/*
const int N = 1200000;

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

*/


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

/*
int mex(set<int> a)
{
    int cur = 0;
    while (a.count(cur)) cur++;
    return cur;
}

void solve(vector<int> a)
{
    int n = a.size();

    vector<vector<int>> nim(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i<n-1; i++) nim[i][n-1] = 0;
    for (int r = n-2; r>=0; r--)
        for (int l = r-1; l>=0; l--)
        {
            set<int> lol;
            for (int j = r+1; j<n; j++) if (a[j]-a[r]>a[r]-a[l]) {lol.insert(nim[r][j]); dp[l][r] = max(dp[l][r], 1 + dp[r][j]);}
            nim[l][r] = mex(lol);
        }



    for (auto it: a) cout<<it<<' ';
    cout<<endl;

    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j<n; j++) cout<<i<<' '<<j<<": "<<nim[i][j]<<' '<<dp[i][j]<<endl;
        cout<<endl;
    }

    //cout<<nim[0][1]<<endl;

}*/

typedef pair<ll, ll> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<ll, ll> > *adj;

public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, ll w);

    // prints shortest path from s
    ll shortestPath(int s, int t);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, ll w)
{
    adj[u].push_back(make_pair(v, w));
    //adj[v].push_back(make_pair(u, w));
}

const ll INF = 1e18;

// Prints shortest paths from src to all other vertices
ll Graph::shortestPath(int src, int dst)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<ll> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        ll u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<ll, ll> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            ll v = (*i).first;
            ll weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[dst];
}

int n, m;
vector<vector<int>> G;

ll find(ll W)
{
    Graph g(2*n+1);
    g.addEdge(2*(n-1), 2*n, 0);
    g.addEdge(2*(n-1)+1, 2*n, 0);
    for (int i = 0; i<n; i++)
        for (auto it: G[i])
        {
            g.addEdge(2*i, 2*it, 1);
            g.addEdge(2*it+1, 2*i+1, 1);
        }
    for (int i = 0; i<n; i++)
    {
        g.addEdge(2*i, 2*i+1, W);
        g.addEdge(2*i+1, 2*i, W);
    }
    return g.shortestPath(0, 2*n);
}

const ll BIG = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m;
    G.resize(n);
    for (int i = 0; i<m; i++)
    {
        int u, v;
        cin>>u>>v; u--; v--;
        G[u].push_back(v);
    }

    ll tmp = find(BIG);
    ll cnt = tmp/BIG;


    if (cnt>=20) {cout<<add((tmp%BIG)%p, sub(po(2, cnt), 1)); return 0;}

    //cout<<tmp<<endl;

    Graph g(20*n+1);

    //cout<<g.shortestPath(0, 20*n)<<endl;

    for (int i = 0; i<n; i++)
    {
        for (auto it: G[i])
        {
            for (int level = 0; level<20; level++)
            {
                if (level%2 == 0) g.addEdge(level*n + i, level*n + it, 1);
                else g.addEdge(level*n + it, level*n + i, 1);
            }
        }
    }

    //cout<<g.shortestPath(0, 3)<<endl;

    for (int i = 0; i<n; i++)
    {
        for (int level = 0; level<19; level++)
        {
            g.addEdge(level*n + i, (level+1)*n + i, (1<<level));
        }
    }
    for (int level = 0; level<20; level++) g.addEdge(level*n + (n-1), 20*n, 0);

    cout<<g.shortestPath(0, 20*n);






}

/*
8 7
2 1
2 3
3 4
 */

/*
23 22
2 1
2 3
3 4
5 4
5 6
7 6
7 8
9 8
9 10
11 10
11 12
13 12
13 14
15 14
15 16
17 16
17 18
19 18
19 20
21 20
21 22
23 22
 */