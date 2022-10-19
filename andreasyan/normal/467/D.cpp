#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 500005;

int n;
int u[N];

int m;
int z;
int t[N][26];
int zz;
int hh[N];

pair<int, int> d[N];

int pro()
{
    string s;
    cin >> s;
    int n = s.size();
    int qr = 0;
    for (int i = 0; i < n; ++i)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
        if (s[i] == 'r')
            ++qr;
    }
    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!t[pos][s[i] - 'a'])
            t[pos][s[i] - 'a'] = ++z;
        pos = t[pos][s[i] - 'a'];
    }
    if (!hh[pos])
        hh[pos] = ++zz;
    d[hh[pos]] = m_p(qr, n);
    return hh[pos];
}

vector<int> a[N], b[N];

int c[N];
vector<int> v;
void dfs1(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs1(h);
    }
    v.push_back(x);
}

int k;
void dfs2(int x)
{
    c[x] = k;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int h = b[x][i];
        if (!c[h])
            dfs2(h);
    }
}

bool cc[N];
pair<int, int> minu[N];
vector<int> g[N];
void dfs(int x)
{
    cc[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!cc[h])
            dfs(h);
        minu[x] = min(minu[x], minu[h]);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        u[i] = pro();
    cin >> m;
    while (m--)
    {
        int x = pro();
        int y = pro();
        a[x].push_back(y);
        b[y].push_back(x);
    }
    for (int x = 1; x <= zz; ++x)
    {
        if (!c[x])
            dfs1(x);
    }
    reverse(v.begin(), v.end());
    memset(c, 0, sizeof c);
    for (int i = 0; i < zz; ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs2(x);
        }
    }
    for (int x = 1; x <= zz; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (c[x] != c[y])
                g[c[x]].push_back(c[y]);
        }
    }
    for (int x = 1; x <= zz; ++x)
    {
        if (minu[c[x]].se == 0 || (d[x] < minu[c[x]]))
            minu[c[x]] = d[x];
    }
    for (int x = 1; x <= zz; ++x)
    {
        if (!cc[x])
            dfs(x);
    }
    pair<ll, ll> ans;
    for (int i = 1; i <= n; ++i)
    {
        ans.fi += minu[c[u[i]]].fi;
        ans.se += minu[c[u[i]]].se;
    }
    cout << ans.fi << ' ' << ans.se << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}