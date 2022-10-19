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
const int N = 600005;

int n;
int a[N], b[N];
vector<int> ga[N], gb[N];

int tinb[N], toutb[N], ti;
void dfsb(int x)
{
    tinb[x] = ++ti;
    for (int i = 0; i < gb[x].size(); ++i)
    {
        int h = gb[x][i];
        dfsb(h);
    }
    toutb[x] = ++ti;
}

set<pair<int, int> > s;

int ans;
void dfsa(int x)
{
    auto it = s.upper_bound(m_p(tinb[x], -1));
    bool z = false;
    if (it != s.end())
    {
        if (it->se < toutb[x])
        {
            z = true;
        }
    }
    pair<int, int> p = m_p(0, 0);
    if (!z)
    {
        s.insert(m_p(tinb[x], toutb[x]));
        it = s.find(m_p(tinb[x], toutb[x]));
        if (it != s.begin())
        {
            --it;
            if (toutb[x] < it->se)
            {
                p = *it;
                s.erase(p);
            }
        }
    }
    ans = max(ans, sz(s));
    for (int i = 0; i < ga[x].size(); ++i)
    {
        int h = ga[x][i];
        dfsa(h);
    }
    if (!z)
    {
        s.erase(m_p(tinb[x], toutb[x]));
        if (p.fi)
            s.insert(p);
    }
}

void solv()
{
    cin >> n;
    ti = 0;
    for (int x = 1; x <= n; ++x)
    {
        ga[x].clear();
        gb[x].clear();
    }
    for (int x = 2; x <= n; ++x)
        cin >> a[x];
    for (int x = 2; x <= n; ++x)
        cin >> b[x];
    a[1] = b[1] = 1;

    for (int x = 2; x <= n; ++x)
        ga[a[x]].push_back(x);
    for (int x = 2; x <= n; ++x)
        gb[b[x]].push_back(x);

    dfsb(1);
    ans = 0;
    dfsa(1);

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
        solv();
    return 0;
}