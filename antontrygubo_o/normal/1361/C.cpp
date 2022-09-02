#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1e9 + 7;


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

struct DSU {
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

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

#define MAXN 1000005
#define MAXM 2000005

vector<pair<int, int> > adj[MAXN];
int cur[MAXN];
bool used[MAXM];
vector<int> tour;

void dfs(int n) {
    while (cur[n] != adj[n].size()) {
        if (used[adj[n][cur[n]].second]) {
            ++cur[n];
            continue;
        }
        auto p = adj[n][cur[n]++];
        used[p.second] = true;
        dfs(p.first);
    }
    tour.push_back(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(2*n);
    for (int i = 0; i<2*n; i++) cin>>a[i];

    for (int deg = 20; deg>=0; deg--)
    {
        vector<vector<int>> groups(1<<deg);
        for (int i = 0; i<2*n; i++) groups[a[i]%(1<<deg)].push_back(i);

        bool check = true;
        for (int i = 0; i<(1<<deg); i++) if (groups[i].size()%2)
        {
            check = false;
            continue;
        }

        if (!check) continue;

        vector<bool> visited(2*n);
        queue<int> Q;
        visited[0] = true;
        Q.push(0);

        vector<bool> checked(1<<deg);

        while (!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            if (!visited[v^1])
            {
                Q.push(v^1); visited[v^1] = true;
            }
            if (!checked[a[v]%(1<<deg)])
            {
                checked[a[v]%(1<<deg)] = true;
                for (auto it: groups[a[v]%(1<<deg)]) if (!visited[it])
                {
                    Q.push(it); visited[it] = true;
                }
            }
        }

        for (int i = 0; i<2*n; i++) if (!visited[i]) {check = false; break;}
        if (!check) continue;

        int M = 0;

        for (int i = 0; i<n; i++)
        {
            adj[2*i].push_back(mp(2*i+1, M));
            adj[2*i+1].push_back(mp(2*i, M));
            M++;
        }

        for (auto vec: groups) if (vec.size())
        {
            if (vec.size()==2)
            {
                int u = vec[0]; int v = vec[1];
                adj[u].push_back(mp(v, M));
                adj[v].push_back(mp(u, M));
                M++;
            }
            else
            {
                int k = vec.size();
                for (int i = 0; i<k; i++)
                {
                    adj[vec[i]].push_back(mp(vec[(i+1)%k], M));
                    adj[vec[(i+1)%k]].push_back(mp(vec[i], M));
                    M++;
                }
                for (int i = 0; i<k/2; i++)
                {
                    adj[vec[i]].push_back(mp(vec[i + k/2], M));
                    adj[vec[i+k/2]].push_back(mp(vec[i], M));
                    M++;
                }
            }
        }

        dfs(0);

        cout<<deg<<endl;

        vector<int> answer;
        int k = tour.size();

        vector<int> written(2*n);

        for (int i = 0; i<k-1; i++)
        {
            if ((tour[i]^1) == tour[i+1] && !written[tour[i]])
            {
                answer.push_back(tour[i]); answer.push_back(tour[i+1]);
                written[tour[i]] = true; written[tour[i+1]] = true;
            }
        }

        for (auto it: answer) cout<<it+1<<' ';

        return 0;
    }



}