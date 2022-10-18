#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
int len[maxn], link[maxn];
map<char, int> to[maxn];
int64_t cnt[maxn];
int sz = 1, last = 0;

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

int used[maxn];

void dfs(int v = 0)
{
    if(used[v]) return;
    used[v] = 1;
    for(auto it: to[v])
    {
        dfs(it.second);
        cnt[v] += cnt[it.second];
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(auto c: s)
        add_letter(c);
    add_letter('#');
    cnt[last] = 1;
    dfs();
    int64_t ans = 0;
    for(int i = 1; i < sz - 1; i++)
        ans += 1LL * (len[i] - len[link[i]]) * cnt[i] * (cnt[i] + 1) / 2;
    cout << ans << "\n";
}