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
const int N = 4e5 + 10;
vi a[N], id[N], near[N];
int n, m, sl = 0;
vi G[N];

void add_edge(int u, int v)
{
    G[u].eb(v);
}

int low[N], num[N], Time = 0, belong[N];
stack<int> st;
void dfs(int u)
{
    num[u] = low[u] = ++Time;
    st.push(u);
    for (int v : G[u])
        if (!belong[v])
        {
            if (!num[v])
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], num[v]);
        }
    if (low[u] >= num[u])
    {
        while (st.top() != u) belong[st.top()] = u, st.pop();
        belong[u] = u;
        st.pop();
    }
}

int deg[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        a[i].resize(m + 2, 0);
        id[i].resize(m + 2, 0);
        near[i].resize(m + 2, 0);
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j)
            if (s[j - 1] == '#') a[i][j] = 1, id[i][j] = ++sl;
    }
    near[0].resize(m + 2, 0);
    near[n + 1].resize(m + 2, 0);
    a[0].resize(m + 2, 0);
    a[n + 1].resize(m + 2, 0);
    for (int i = 1; i <= m; ++i)
        for (int j = n; j; --j)
            if (a[j][i]) near[j][i] = j;
            else near[j][i] = near[j + 1][i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j])
            {
                if (a[i - 1][j]) add_edge(id[i][j], id[i - 1][j]);
                if (near[i + 1][j]) add_edge(id[i][j], id[near[i + 1][j]][j]);
                if (near[i][j - 1]) add_edge(id[i][j], id[near[i][j - 1]][j - 1]);
                if (near[i][j + 1]) add_edge(id[i][j], id[near[i][j + 1]][j + 1]);
            }
    for (int i = 1; i <= sl; ++i)
        if (!num[i]) dfs(i);
    for (int i = 1; i <= sl; ++i)
        for (int j : G[i])
            if (belong[i] != belong[j]) deg[belong[j]]++;
    int res = 0;
    for (int i = 1; i <= sl; ++i)
        if (i == belong[i] && deg[i] == 0) res++;
    cout << res;
    return 0;
}