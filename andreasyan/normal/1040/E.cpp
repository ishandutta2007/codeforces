#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const long long M = 1000000007;

int n, m;
long long k;
long long a[N];
pair<int, int> b[N];

bool so(const pair<int, int>& t1, const pair<int, int>& t2)
{
    return (a[t1.first] ^ a[t1.second]) < (a[t2.first] ^ a[t2.second]);
}

long long ast[N];

vector<int> g[N];

int q;
bool c[N];
void dfs(int x)
{
    ++q;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h);
    }
}

long long dp[N];

vector<pair<int, int> > v;
long long solv()
{
    for (int i = 0; i < v.size(); ++i)
    {
        g[v[i].first].push_back(v[i].second);
        g[v[i].second].push_back(v[i].first);
    }
    vector<int> qq;
    qq.push_back(0);
    for (int i = 0; i < v.size(); ++i)
    {
        if (!c[v[i].first])
        {
            q = 0;
            dfs(v[i].first);
            qq.push_back(q);
        }
    }
    int nq = 0;
    for (int i = 1; i < qq.size(); ++i)
    {
        dp[i] = (dp[i - 1] * 2 + ((ast[qq[i]] - 2 + M) % M) * ast[nq]) % M;
        nq += qq[i];
    }
    for (int i = 0; i < v.size(); ++i)
    {
        g[v[i].first].pop_back();
        g[v[i].second].pop_back();
    }
    for (int i = 0; i < v.size(); ++i)
    {
        c[v[i].first] = c[v[i].second] = false;
    }
    return (dp[qq.size() - 1] * ast[n - nq]) % M;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i].first >> b[i].second;
    }
    long long ans = 0;
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
    sort(b, b + m, so);
    v.push_back(b[0]);
    for (int i = 1; i < m; ++i)
    {
        if ((a[b[i].first] ^ a[b[i].second]) == (a[b[i - 1].first] ^ a[b[i - 1].second]))
            v.push_back(b[i]);
        else
        {
            ans = (ans + solv()) % M;
            v.clear();
            v.push_back(b[i]);
        }
    }
    ans = (ans + solv() % M);
    cout << (ast[n] * ast[k] - ans + M) % M << endl;
    return 0;
}