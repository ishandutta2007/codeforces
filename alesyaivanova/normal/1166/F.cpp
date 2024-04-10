#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define pf emplace_front
#define ff first
#define ss second
#define pii pair<int, int>

const int MAXN = 500009;
vector<int> g[MAXN];
int p[MAXN];
map<int, int> mp[MAXN];
map<int, int> kek[MAXN];
int num[MAXN];
bool used[MAXN];
int n, m, c, q;
vector<int> cmp[MAXN];
int sz[MAXN];

void dfs(int v, int i)
{
    used[v] = true;
    cmp[i].pb(v);
    if (v >= n)
    {
        int to = num[v];
        kek[to][p[v]]--;
        if (kek[to][p[v]] == 0)
            kek[to].erase(p[v]);
        kek[to][i]++;
    }
    p[v] = i;
    sz[i]++;
    for (int to : g[v])
    {
        if (!used[to])
            dfs(to, i);
    }
}

void merg(int i, int e)
{
    if (i == e)
        return;
    if (sz[e] > sz[i])
    {
        int c = i;
        i = e;
        e = c;
    }
    for (int v : cmp[e])
    {
        cmp[i].pb(v);
        if (v >= n)
        {
            int to = num[v];
            kek[to][p[v]]--;
            if (kek[to][p[v]] == 0)
                kek[to].erase(p[v]);
            kek[to][i]++;
        }
        p[v] = i;
        sz[i]++;
    }
    cmp[e].resize(0);
    cmp[e].shrink_to_fit();
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> c >> q;
    int cnt_v = n;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        if (mp[b].find(c) != mp[b].end())
        {
            int to = mp[b][c];
            g[a].pb(to);
            g[to].pb(a);
        }
        else
        {
            g[a].pb(cnt_v);
            g[cnt_v].pb(a);
            kek[b][cnt_v]++;
            mp[b][c] = cnt_v;
            num[cnt_v] = b;
            p[cnt_v] = cnt_v;
            sz[cnt_v] = 1;
            cnt_v++;
        }

        if (mp[a].find(c) != mp[a].end())
        {
            int to = mp[a][c];
            g[b].pb(to);
            g[to].pb(b);
        }
        else
        {
            g[b].pb(cnt_v);
            g[cnt_v].pb(b);
            kek[a][cnt_v]++;
            mp[a][c] = cnt_v;
            num[cnt_v] = a;
            p[cnt_v] = cnt_v;
            sz[cnt_v] = 1;
            cnt_v++;
        }
    }
    for (int i = 0; i < cnt_v; i++)
    {
        /*cout << i << ": ";
        for (int to : g[i])
            cout << to <<  " ";
        cout << "\n";*/
        if (!used[i])
            dfs(i, i);
    }
    for (int j = 0; j < q; j++)
    {
        char x;
        cin >> x;
        if (x == '+')
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--; c--;
            if (mp[b].find(c) != mp[b].end())
            {
                int to = mp[b][c];
                g[a].pb(to);
                g[to].pb(a);
                merg(p[to], p[a]);
            }
            else
            {
                g[a].pb(cnt_v);
                g[cnt_v].pb(a);
                kek[b][cnt_v]++;
                mp[b][c] = cnt_v;
                num[cnt_v] = b;
                p[cnt_v] = cnt_v;
                sz[cnt_v] = 1;
                cmp[cnt_v].pb(cnt_v);
                merg(p[cnt_v], p[a]);
                cnt_v++;
            }

            if (mp[a].find(c) != mp[a].end())
            {
                int to = mp[a][c];
                g[b].pb(to);
                g[to].pb(b);
                merg(p[to], p[b]);
            }
            else
            {
                g[b].pb(cnt_v);
                g[cnt_v].pb(b);
                kek[a][cnt_v]++;
                mp[a][c] = cnt_v;
                num[cnt_v] = a;
                p[cnt_v] = cnt_v;
                sz[cnt_v] = 1;
                cmp[cnt_v].pb(cnt_v);
                merg(p[cnt_v], p[b]);
                cnt_v++;
            }
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            //cout << p[a] << " " << p[b] << "\n";
            /*for (pii y : kek[b])
                cout << y.ff << "\n";*/
            if (p[a] == p[b] || kek[b].find(p[a]) != kek[b].end())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}