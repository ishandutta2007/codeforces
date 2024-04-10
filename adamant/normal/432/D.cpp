#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;

#define fpos skfsl
int len[maxn], fpos[maxn], link[maxn], used[maxn], cnt[maxn];
map<char, int> to[maxn];
int sz = 1, last;

void add_letter(char c)
{
    int p = last;
    last = sz++;
    len[last] = fpos[last] = len[p] + 1;
    for(; p != -1 && !to[p][c]; p = link[p]) to[p][c] = last;
    if(p == -1) return;
    int q = to[p][c];
    if(len[q] == len[p] + 1)
    {
        link[last] = q;
        return;
    }
    int cl = sz++;
    to[cl] = to[q];
    link[cl] = link[q];
    fpos[cl] = fpos[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for(; p != -1 && to[p][c] == q; p = link[p]) to[p][c] = cl;
}

void dfs(int v)
{
    if(used[v]) return;
    used[v] = 1;
    for(auto it: to[v])
    {
        dfs(it.second);
        cnt[v] += cnt[it.second];
    }
}

void solve(string s)
{
    link[0] = -1;
    int n = s.size();
    for(auto c: s) add_letter(c);
    vector<int> ans;
    for(; last; last = link[last])
    {
        if(len[last] == fpos[last])
            ans.push_back(last);
        cnt[last] = 1;
    }
    dfs(0);
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto it: ans)
        cout << len[it] << ' ' << cnt[it] << "\n";
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    solve(s);
    return 0;
}