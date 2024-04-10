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
const int N = 100005;

int n;
int a[N], b[N];

vector<int> g[N];

char ans[N];

void dfs(int x)
{
    ans[x - 1] = '1';
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!ans[h - 1])
            dfs(h);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        g[i].clear();

    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
        v.push_back(m_p(a[i], i));
    sort(all(v));

    int maxu = 0;
    int maxb;
    for (int j = 0; j < n; ++j)
    {
        int i = v[j].se;
        if (b[i] > maxu)
        {
            maxu = b[i];
            maxb = i;
        }
        if (i != maxb)
        {
            g[maxb].push_back(i);
        }
    }

    v.clear();
    for (int i = 1; i <= n; ++i)
        v.push_back(m_p(b[i], i));
    sort(all(v));

    maxu = 0;
    int maxa;
    for (int j = 0; j < n; ++j)
    {
        int i = v[j].se;
        if (a[i] > maxu)
        {
            maxu = a[i];
            maxa = i;
        }
        if (i != maxa)
        {
            g[maxa].push_back(i);
        }
    }

    for (int i = 0; i <= n; ++i)
        ans[i] = 0;
    dfs(maxa);
    dfs(maxb);
    for (int i = 0; i < n; ++i)
    {
        if (!ans[i])
            ans[i] = '0';
    }
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}