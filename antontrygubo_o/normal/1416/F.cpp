#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define mp make_pair

int p = 1000000007;




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
}*/


struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};


void solve()
{

    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) cin>>a[i][j];

    int cnt = 0;

    vector<vector<int>> special(n, vector<int>(m));
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
        {
            special[i][j] = 1;
            if (i>0 && a[i-1][j]<a[i][j]) special[i][j] = 0;
            if (j>0 && a[i][j-1]<a[i][j]) special[i][j] = 0;
            if (i<n-1 && a[i+1][j]<a[i][j]) special[i][j] = 0;
            if (j<m-1 && a[i][j+1]<a[i][j]) special[i][j] = 0;
            cnt+=special[i][j];
        }

    Dinic G(2 + 2*n*m, 0, 1 + 2*n*m);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (special[i][j])
        {
            //cout<<i<<' '<<j<<endl;
            G.add_edge(0, 1 + i*m + j, 1);
            if (i>0 && a[i-1][j]==a[i][j]) G.add_edge(1 + i*m + j, (1 + n*m) + (i-1)*m + j, 1);
            if (j>0 && a[i][j-1]==a[i][j]) G.add_edge(1 + i*m + j, (1 + n*m) + i*m + (j-1), 1);
            if (i<n-1 && a[i+1][j]==a[i][j]) G.add_edge(1 + i*m + j, (1 + n*m) + (i+1)*m + j, 1);
            if (j<m-1 && a[i][j+1]==a[i][j]) G.add_edge(1 + i*m + j, (1 + n*m) + i*m + (j+1), 1);
        }

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) G.add_edge( (1+n*m) + i*m + j, 1 + 2*n*m, 1);

    ll ans = G.flow();
    /*cout<<cnt<<' '<<ans<<endl;
    cout<<endl;*/

    if (cnt!=ans) {cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;


    vector<pair<int, int>> edges;

    for (auto it: G.edges) if (it.flow==-1 && it.u !=0 && it.v != 1 + 2*n*m && it.u<it.v)
    {
        edges.push_back(mp(it.u - 1, it.v - 1 - n*m));
    }

    //for (auto it: edges) cout<<it.first<<' '<<it.second<<endl;

    vector<int> indeg(n*m);
    for (auto it: edges) indeg[it.second]++;

    vector<bool> visited(n*m);

    vector<pair<int, int>> pairs;

    vector<int> nxt(n*m, -1);
    for (auto it: edges) nxt[it.first] = it.second;

    //for (int i = 0; i<n*m; i++) cout<<i<<": "<<nxt[i]<<endl;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (special[i][j] && indeg[i*m+j]==0)
        {
            //cout<<"cell: "<<i<<' '<<j<<endl;
            int st = i*m+j;
            while (special[st/m][st%m])
            {
                int en = nxt[st];
                //cout<<st<<' '<<en<<endl;
                pairs.push_back(mp(st, en));
                visited[st] = true; visited[en] = true;
                if (special[en/m][en%m]) st = nxt[en];
                else break;
            }
        }

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (special[i][j] && !visited[i*m+j])
        {
            int st = i*m+j;
            while (!visited[st])
            {
                int en = nxt[st];
                pairs.push_back(mp(st, en));
                visited[st] = true; visited[en] = true;
                st = nxt[en];
            }
        }

    vector<vector<char>> grid(n, vector<char>(m, '?'));

    vector<vector<int>> values(n, vector<int>(m));

    for (auto it: pairs)
    {
        int x1 = it.first/m; int y1 = it.first%m;
        int x2 = it.second/m; int y2 = it.second%m;

        if (x1==x2-1)
        {
            grid[x1][y1] = 'D'; grid[x2][y2] = 'U';
        }
        if (x1==x2+1)
        {
            grid[x1][y1] = 'U'; grid[x2][y2] = 'D';
        }
        if (y1==y2-1)
        {
            grid[x1][y1] = 'R'; grid[x2][y2] = 'L';
        }
        if (y1==y2+1)
        {
            grid[x1][y1] = 'L'; grid[x2][y2] = 'R';
        }

        values[x1][y1] = 1; values[x2][y2] = a[x2][y2] - 1;
    }

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (grid[i][j]=='?')
        {
            if (i>0 && a[i-1][j]<a[i][j])
            {
                values[i][j] = a[i][j] - a[i-1][j]; grid[i][j] = 'U'; continue;
            }
            if (j>0 && a[i][j-1]<a[i][j])
            {
                values[i][j] = a[i][j] - a[i][j-1]; grid[i][j] = 'L'; continue;
            }
            if (i<n-1 && a[i+1][j]<a[i][j])
            {
                values[i][j] = a[i][j] - a[i+1][j]; grid[i][j] = 'D'; continue;
            }
            if (j<m-1 && a[i][j+1]<a[i][j])
            {
                values[i][j] = a[i][j] - a[i][j+1]; grid[i][j] = 'R'; continue;
            }
        }

    for (auto vec: values)
    {
        for (auto x: vec) cout<<x<<' ';
        cout<<endl;
    }
    for (auto vec: grid)
    {
        for (auto x: vec) cout<<x<<' ';
        cout<<endl;
    }



}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();


}

/*
1
5 5
4 4 2 2 2
4 3 4 3 2
3 3 4 3 3
3 3 3 3 4
3 3 4 3 3
 */