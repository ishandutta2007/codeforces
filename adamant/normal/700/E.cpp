#include <bits/stdc++.h>

using namespace std;

#define fpos adamant
const int maxn = 2e5, sigma = 26;
int len[2 * maxn], link[2 * maxn], fpos[2 * maxn];
int to[2 * maxn][sigma];
int par[2 * maxn];
int sz = 1, last = 0;

void add_letter(char c)
{
    c -= 'a';
    int p = last;
    last = sz++;
    par[last] = p;
    len[last] = fpos[last] = len[p] + 1;
    for(; to[p][c] == 0; p = link[p])
        to[p][c] = last;
    if(to[p][c] == last)
        return;
    int q = to[p][c];
    if(len[q] == len[p] + 1)
    {
        link[last] = q;
        return;
    }
    int cl = sz++;
    memcpy(to[cl], to[q], sizeof(to[q]));
    link[cl] = link[q];
    fpos[cl] = fpos[q];
    len[cl] = len[p] + 1;
    par[cl] = p;
    link[last] = link[q] = cl;
    for(; to[p][c] == q; p = link[p])
        to[p][c] = cl;
}

int dp[2 * maxn];
int in[2 * maxn], out[2 * maxn];
const int logn = 18;
int up[2 * maxn][logn];
vector<int> g[2 * maxn], gf[2 * maxn];
int t = 0;

void dfs(int v = 0)
{
    in[v] = t++;
    up[v][0] = link[v];
    for(int i = 1; i < logn; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for(auto u: g[v])
        dfs(u);
    out[v] = t;
}

int mx[8 * maxn];
void upd(int p, int c, int v = 1, int l = 0, int r = 2 * maxn)
{
    mx[v] = max(mx[v], c);
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    if(p < m)
        upd(p, c, 2 * v, l, m);
    else
        upd(p, c, 2 * v + 1, m, r);
}

int get(int a, int b, int v = 1, int l = 0, int r = 2 * maxn)
{
    if(a <= l && r <= b)
        return mx[v];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return max(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(auto c: s)
        add_letter(c);
    for(int i = 1; i < sz; i++)
    {
        g[link[i]].push_back(i);
        gf[fpos[i]].push_back(i);
    }
    dfs();
    for(int i = 1; i < sz; i++)
    {
        if(gf[i].empty())
            continue;
        for(auto v: gf[i])
        {
            int u = v;
            for(int i = logn - 1; i >= 0; i--)
                if(get(in[up[u][i]], out[up[u][i]]) - len[up[u][i]] < fpos[v] - len[v])
                    u = up[u][i];
            if(get(in[u], out[u]) - len[u] < fpos[v] - len[v])
                u = link[u];
            dp[v] = max(dp[par[v]], 1 + dp[u]);
        }
        upd(in[*min_element(begin(gf[i]), end(gf[i]))], i);
    }
    cout << dp[last] << "\n";
    return 0;
}