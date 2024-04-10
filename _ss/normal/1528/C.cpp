#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 3e5 + 10;

vi G1[N], G2[N];
int n, sz[N], bit[N];

void add(int pos, int val)
{
    for (int i = pos; i <= n; i += (i & -i)) bit[i] += val;
}

int get(int pos)
{
    int res = 0;
    for (int i = pos; i; i -= (i & -i)) res += bit[i];
    return res;
}

int lw(int val)
{
    int pos = 0;
    for (int i = 18; i >= 0; --i)
        if ((pos | (1 << i)) <= n && bit[pos | (1 << i)] <= val) pos |= (1 << i), val -= bit[pos];
    return pos;
}

void dfs_sz(int u, int r)
{
    sz[u] = 1;
    for (int &v : G2[u])
        {
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[G2[u][0]]) swap(v, G2[u][0]);
        }
}

int Time = 0, in[N], out[N], head[N], p[N];

void dfs_hld(int u, int r)
{
    in[u] = ++Time;
    for (int v : G2[u])
        {
            p[v] = u;
            head[v] = v == G2[u][0] ? head[u] : v;
            dfs_hld(v, u);
        }
    out[u] = Time;
}

int res = 0;
void dfs(int u, int r)
{
    stack<pii> st;
    if (get(out[u]) - get(in[u] - 1) == 0)
    {
        int x = u;
        while (x > 0)
        {
            if (get(in[x]) > get(in[head[x]] - 1))
            {
                int pos = lw(get(in[head[x]] - 1)) + 1;
                st.push(mp(pos, 1));
                add(pos, -1);
                break;
            }
            x = p[head[x]];
        }
        st.push(mp(in[u], -1));
        add(in[u], 1);
        res = max(res, get(n));
    }
    for (int v : G1[u])
        if (v != r) dfs(v, u);
    while (!st.empty())
    {
        add(st.top().fi, st.top().se);
        st.pop();
    }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) G1[i].clear(), G2[i].clear();
        for (int i = 2, v; i <= n; ++i)
        {
            cin >> v;
            G1[v].eb(i);
        }
        for (int i = 2, v; i <= n; ++i)
        {
            cin >> v;
            G2[v].eb(i);
        }
        Time = 0;
        head[1] = 1;
        dfs_sz(1, 0);
        dfs_hld(1, 0);
        res = 0;
        dfs(1, 0);
        cout << res << "\n";
    }
    return 0;
}