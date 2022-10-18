#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5, sigma = 27;
int to[maxn][sigma];
int len[maxn], link[maxn];
unordered_set<int> occ[maxn];
int sz = 1, last = 0;

void add_letter(char c, int k)
{
    c -= 'a';
    int p = last;
    last = sz++;
    occ[last].insert(k);
    len[last] = len[p] + 1;
    for(; !to[p][c]; p = link[p]) to[p][c] = last;
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
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for(; to[p][c] == q; p = link[p]) to[p][c] = cl;
}

int cnt[maxn];
vector<int> g[maxn];

void dfs(int v = 0)
{
    for(auto u: g[v])
    {
        dfs(u);
        for(auto it: occ[u])
            occ[v].insert(it);
        occ[u].clear();
    }
    cnt[v] = occ[v].size();
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s[n];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(auto c: s[i])
            add_letter(c, i);
        add_letter('z' + 1, i);
    }
    for(int i = 1; i < sz; i++)
        g[link[i]].push_back(i);
    dfs();
    for(int i = 0; i < n; i++)
    {
        int64_t ans = 0;
        int v = 0, ln = 0;
        if(k > n)
        {
            cout << 0 << ' ';
            continue;
        }
        for(auto c: s[i])
        {
            c -= 'a';
            v = to[v][c];
            while(cnt[v] < k)
                v = link[v];
            ln = min(ln + 1, len[v]);
            ans += ln;
        }
        cout << ans << " ";
    }
}