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
const int INF = 1000000009;

int n, C, D;
vector<pair<int, int> > c, d;


int solvv(vector<pair<int, int> > v, int V)
{
    sort(all(v));

    vector<int> p;
    for (int i = 0; i < sz(v); ++i)
    {
        if (p.empty())
            p.push_back(v[i].se);
        else
            p.push_back(max(p.back(), v[i].se));
    }

    int ans = 0;
    int j = -1;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        V -= v[i].fi;

        j = min(j, i - 1);
        while (j + 1 < i && v[j + 1].fi <= V)
        {
            ++j;
        }
        if (j >= 0)
            ans = max(ans, v[i].se + p[j]);

        V += v[i].fi;
    }
    return ans;
}

void solv()
{
    cin >> n >> C >> D;
    while (n--)
    {
        int b, p;
        char u;
        cin >> b >> p >> u;
        if (u == 'C')
            c.push_back(m_p(p, b));
        else
            d.push_back(m_p(p, b));
    }

    int ans = 0;

    int maxc = -INF, maxd = -INF;
    for (int i = 0; i < sz(c); ++i)
    {
        if (c[i].fi <= C)
        {
            maxc = max(maxc, c[i].se);
        }
    }
    for (int i = 0; i < sz(d); ++i)
    {
        if (d[i].fi <= D)
        {
            maxd = max(maxd, d[i].se);
        }
    }

    ans = max(ans, maxc + maxd);

    ans = max(ans, solvv(c, C));
    ans = max(ans, solvv(d, D));

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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}