#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000010;
vector<int> g1[MAX_N];
vector<int> rg1[MAX_N];
int n, m, cnt;
int t[MAX_N];
vector<int> ist;
vector<int> st;
bool used[MAX_N];
vector<int> g[20];
vector<int> rg[20];
int mask_g[20];
int mask_rg[20];

void dfs(int v, int st)
{
    used[v] = true;
    if (t[v] >= 1)
    {
        g[st].push_back(t[v] - 1);
        rg[t[v] - 1].push_back(st);
    }
    for (int to : g1[v])
    {
        if (used[to])
            continue;
        dfs(to, st);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g1[a].push_back(b);
        rg1[b].push_back(a);
    }
    int cnt2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (rg1[i].empty())
        {
            ist.push_back(i);
            t[i] = -1;
            cnt++;
        }
        if (g1[i].empty())
        {
            st.push_back(i);
            t[i] = cnt2;
            cnt2++;
        }
    }
    for (int j = 0; j < cnt; j++)
    {
        int v = ist[j];
        for (int i = 0; i < n; i++)
            used[i] = false;
        dfs(v, j);
    }
    for (int i = 0; i < cnt; i++)
    {
        for (int v: g[i])
            mask_g[i] |= (1 << v);
        for (int v: rg[i])
            mask_rg[i] |= (1 << v);
    }
    for (int mask = 1; mask < (1 << cnt) - 1; mask++)
    {
        int rmask = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (mask & (1 << i))
                rmask |= mask_g[i];
        }
        if (__builtin_popcount(mask) >= __builtin_popcount(rmask))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}