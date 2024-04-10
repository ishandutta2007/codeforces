#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int len[maxn], link[maxn];
map<char, int> to[maxn];
int mx[maxn], mn[maxn];
int sz = 1, last;

void add_letter(char c)
{
    int p = last;
    last = sz++;
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
    to[cl] = to[q];
    link[cl] = link[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for(; to[p][c] == q; p = link[p]) to[p][c] = cl;
}

vector<int> g[maxn];
map<int, int> occ[maxn];

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(auto c: s)
        add_letter(c);
    for(int i = 1; i < sz; i++)
    {
        mx[i] = len[i] + 1;
        mn[i] = len[link[i]] + 1;
        g[len[i]].push_back(i);
    }
    reverse(g, g + maxn);
    int z;
    cin >> z;
    while(z--)
    {
        for(int i = 0; i < sz; i++)
            occ[i].clear();
        string s;
        int l, r;
        cin >> s >> l >> r;
        int ln = 0;
        int v = 0;
        for(auto c: s)
        {
            while(v && !to[v][c]) v = link[v];
            ln = min(ln, len[v]);
            if(to[v][c]) v = to[v][c], ln++;
            occ[v][ln]++;
        }
        for(auto it: g)
        for(auto v: it)
        {
            occ[v][len[v]];
            occ[v][len[link[v]] + 1];
            for(auto it = --occ[v].end(); it != occ[v].begin(); it--)
            {
                auto t = it;
                t--;
                occ[v][t->first] += it->second;
            }
            bool ok = 0;
            for(auto it = occ[v].begin(); it != occ[v].end(); it++)
                if(it->second >= l && it->second <= r)
                {
                    mn[v] = max(mn[v], it->first);
                    ok = 1;
                    break;
                }
            if(!ok) mn[v] = len[v] + 1;
            for(auto it = --occ[v].end(); ; it--)
                if(it->second >= l && it->second <= r)
                {
                    mx[v] = min(mx[v], it->first + 1);
                    ok = 1;
                    break;
                }
                else if(it == occ[v].begin())
                {
                    break;
                }
            if(!ok) mx[v] = len[link[v]] + 1;
            occ[link[v]][len[link[v]]] += occ[v][len[link[v]] + 1];
        }
    }
    int ans = 0;
    for(int i = 1; i < sz; i++)
        ans += max(0, mx[i] - mn[i]);
    cout << ans << "\n";
    return 0;
}