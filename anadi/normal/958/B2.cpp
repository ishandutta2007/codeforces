#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template < typename _T > inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }

#ifdef LOCAL
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

// ********************** CODE ********************** //

struct SegmentTree { // (+, max)
    const static int MAX = 1 << 18;
    LL INF = 1e18 + 7;
    vector<PLL> tree;
    vector<LL> lazy;
    SegmentTree()
    {
        tree.resize(2 * MAX, {0, 0}), lazy.resize(2 * MAX, 0);
        for (int i = 0; i <= MAX - 1; i++)
            tree[i + MAX].second = i;
        for (int i = MAX - 1; i; i--)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]); // (*)
    }
    inline void propagate(int node, int l, int r)
    {
        if (!lazy[node])
            return;
        tree[node].first += lazy[node];
        if (l != r)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update(int a, int b, LL val, int node = 1, int l = 0, int r = MAX - 1)
    {
        propagate(node, l, r);
        if (b < l || r < a)
            return;
        if (a <= l && r <= b)
            lazy[node] += val, propagate(node, l, r);
        else
        {
            update(a, b, val, 2 * node, l, (l + r) / 2);
            update(a, b, val, 2 * node + 1, (l + r) / 2 + 1, r);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]); // (*)
        }
    }
    PLL query(int a, int b, int node = 1, int l = 0, int r = MAX - 1)
    {
        propagate(node, l, r);
        if (b < l || r < a)
            return {-INF, 0}; // (*)
        if (a <= l && r <= b)
            return tree[node];
        return max(query(a, b, 2 * node, l, (l + r) / 2), query(a, b, 2 * node + 1, (l + r) / 2 + 1, r)); // (*)
    }
};

const int N = 1e5 + 7;

int n, ans[N], mark[N];
vector < int > G[N];

void dfs(int v, int f, int d, int &mx, int &id)
{
    if(d > mx)
    {
        mx = d;
        id = v;
    }
    for(auto u: G[v])
        if(u != f)
            dfs(u, v, d + 1, mx, id);
}

int F[N], D[N], SZ[N], pre[N], cnt = 0, who[N];
SegmentTree tree;

int dfs2(int v)
{
    tree.update(cnt, cnt, D[v]);
    who[cnt] = v;
    pre[v] = cnt++;
    for(auto u: G[v])
    {
        if(u != F[v])
        {
            F[u] = v;
            D[u] = D[v] + 1;
            SZ[v] += dfs2(u);
        }
    }
    return ++SZ[v];
}

int main()
{
    _upgrade
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans[1] = 1;
    int mx = -1, root = 0;
    dfs(1, 0, 0, mx, root);
    dfs2(root);
    mark[root] = true;
    for(int i = 2; i <= n; i++)
    {
        PLL tmp = tree.tree[1];
        ans[i] = ans[i - 1] + tmp.first;
        if(tmp.first == 0) continue;
        int v = who[tmp.second];
        while(!mark[v])
        {
            tree.update(pre[v], pre[v] + SZ[v] - 1, -1);
            mark[v] = 1;
            v = F[v];
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
	return 0;
}