#include <bits/stdc++.h>

using namespace std;

const int logn = 18;
const int maxn = 3e5 + 42;
const int sigma = 26;

vector<int> to[2 * maxn * logn];
int link[2 * maxn * logn];
int cnt[2 * maxn * logn];

vector<string> str_set[2][logn];
int root[2][logn];
int sz = 1;

void clear(int v)
{
    if(link[v] == 0)
        return;
    link[v] = 0;
    for(auto u: to[v])
        clear(u);
    to[v].clear();
    to[v].shrink_to_fit();
}

int que[maxn];
void push_links(int v)
{
    link[v] = v;
    que[0] = v;
    int st = 0, fi = 1;
    while(st < fi)
    {
        int v = que[st++];
        int u = link[v];
        cnt[v] += cnt[u];
        for(int c = 0; c < sigma; c++)
        {
            if(to[v][c])
            {
                que[fi++] = to[v][c];
                link[to[v][c]] = st > 1 ? to[u][c] : v;
            }
            else
            {
                to[v][c] = st > 1 ? to[u][c] : v;
            }
        }
    }
}

void add_str(int v, string s)
{
    for(auto c: s)
    {
        c -= 'a';
        if(!to[v][c])
        {
            to[sz].resize(sigma);
            to[v][c] = sz++;
        }
        v = to[v][c];
    }
    cnt[v]++;
}

void add_str(string s, int c)
{
    int k = 0;
    str_set[c][k].push_back(s);
    while(str_set[c][k].size() == 1 << (k + 1))
    {
        for(auto it: str_set[c][k])
            str_set[c][k + 1].push_back(it);
        str_set[c][k].clear();
        clear(root[c][k]);
        k++;
    }
    clear(root[c][k]);
    to[sz].resize(sigma);
    root[c][k] = sz++;
    for(auto it: str_set[c][k])
        add_str(root[c][k], it);
    push_links(root[c][k]);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    for(int z = 1; z <= q; z++)
    {
        char type;
        string s;
        cin >> type >> s;
        if(type == '1')
        {
            add_str(s, 0);
        }
        if(type == '2')
        {
            add_str(s, 1);
        }
        if(type == '3')
        {
            int ans = 0;
            for(int x = 0; x <= 1; x++)
            {
                for(int y = 0; y < logn; y++)
                {
                    if(str_set[x][y].empty())
                        continue;
                    int v = root[x][y];
                    for(auto c: s)
                    {
                        c -= 'a';
                        v = to[v][c];
                        ans += (1 - 2 * x) * cnt[v];
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}