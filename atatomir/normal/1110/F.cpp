#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";
#define lSon (node << 1)
#define rSon (lSon | 1)

ostream& operator<<(ostream& cerr, vector<int> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const ll inf = 1LL << 60;
const int maxN = 500011;

struct query {
    int l, r, id;
};

struct aint {
    ll data[maxN * 4 + 11];

    void init(int n) {
        for (int i = 0; i <= 4 * n; i++)
            data[i] = inf;
    }

    void upd(int node, int l, int r, int pos, ll v) {
        if (l == r) {
            data[node] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) upd(lSon, l, mid, pos, v);
        else            upd(rSon, mid + 1, r, pos, v);
        data[node] = min(data[lSon], data[rSon]);
    }

    ll que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];
        int mid = (l + r) >> 1;
        ll ans = inf;
        if (qL <= mid) ans = min(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid) ans = min(ans, que(rSon, mid + 1, r, qL, qR));
        return ans;
    }
};


int n, m, i, x, c, l, r;
vector<pair<int, int> > adj[maxN];
vector<query> queries[maxN];
int pond[maxN];
bool leaf[maxN];
aint work;

bool dead[maxN];
int down[maxN];
ll dist[maxN];
ll solution[maxN];
vector<int> nodes = {};

void clean_up(int node) {
    for (int i = 0; i < adj[node].size(); i++) {
        if (dead[adj[node][i].first]) {
            adj[node][i] = adj[node].back();
            adj[node].pop_back();
            i--;
        }
    }
}

int pond_sum(int node, int root) {
    int ans = pond[node];
    nodes.pb(node);

    clean_up(node);
    for (auto e : adj[node])
        if (e.first != root)
            ans += pond_sum(e.first, node);
    return ans;
}

int find_root(int node, int root, int target) {
    bool ok = true;
    down[node] = pond[node];

    for (auto e: adj[node]) {
        if (e.first == root) continue;
        int ans = find_root(e.first, node, target); 
        if (ans) return ans;
        down[node] += down[e.first];
        ok &= (down[e.first] <= target / 2);
    }

    ok &= ((target - down[node]) <= (target / 2));
    if (ok) return node;
    return 0;
}

void get_distance(int node, int root) {
    for (auto e : adj[node]) {
        if (e.first == root) continue;
        dist[e.first] = dist[node] + e.second;
        get_distance(e.first, node);
    }
}

void centroid(int R) {
    int target = pond_sum(R, 0); 

    R = find_root(R, 0, target);
    assert(R > 0);
    dist[R] = 0;
    get_distance(R, 0);


    for (auto e: nodes) 
        if (leaf[e]) 
            work.upd(1, 1, n, e, dist[e]);
            
    for (auto node : nodes) 
        for (auto act_query: queries[node]) 
            solution[act_query.id] = min(solution[act_query.id], work.que(1, 1, n, act_query.l, act_query.r) + dist[node]);

    for (auto e: nodes) 
        if (leaf[e]) 
            work.upd(1, 1, n, e, inf);

    dead[R] = true;
    nodes.clear();
    for (auto e : adj[R])
        centroid(e.first);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 2; i <= n; i++) {
        scanf("%d%d", &x, &c);
        adj[i].pb(mp(x, c));
        adj[x].pb(mp(i, c));
    }

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &l, &r);
        queries[x].pb({l, r, i});
        solution[i] = inf;
    }

    for (i = 1; i <= n; i++) {
        pond[i] = 1 + queries[i].size();
        leaf[i] = adj[i].size() == 1;
    }

    work.init(n);
    centroid(1);

    for (i = 1; i <= m; i++)
        printf("%lld\n", solution[i]);


    return 0;
}