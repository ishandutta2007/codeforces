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
const int N = 200005;

struct ban
{
    int ty;
    int x;
};

int n;
ban a[N];

int z;
vector<int> v;
map<int, int> mp;
int rmp[N];

set<int> s[2];
pair<int, ll> t[N * 4];

pair<int, ll> mer(const pair<int, ll>& a, const pair<int, ll>& b)
{
    return m_p(a.fi + b.fi, a.se + b.se);
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos].fi += y;
        t[pos].se += y * 1LL * rmp[x];
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ll qry(int tl, int tr, int q, int pos)
{
    if (tl == tr)
    {
        return min(q, t[pos].fi) * 1LL * rmp[tl];
    }
    int m = (tl + tr) / 2;
    if (q > t[pos * 2 + 1].fi)
        return qry(tl, m, q - t[pos * 2 + 1].fi, pos * 2) + t[pos * 2 + 1].se;
    return qry(m + 1, tr, q, pos * 2 + 1);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i].ty, &a[i].x);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i].x > 0)
        {
            v.push_back(a[i].x);
        }
    }

    sort(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
            rmp[z] = v[i];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i].x < 0)
        {
            ubd(1, z, mp[-a[i].x], -1, 1);
            s[a[i].ty].erase(-a[i].x);
        }
        else
        {
            ubd(1, z, mp[a[i].x], 1, 1);
            s[a[i].ty].insert(a[i].x);
        }

        if (s[0].empty() && s[1].empty())
        {
            printf("0\n");
            continue;
        }
        if (s[1].empty())
        {
            printf("%lld\n", t[1].se);
            continue;
        }
        if (s[0].empty())
        {
            printf("%lld\n", (t[1].se - *s[1].begin()) * 2 + *s[1].begin());
            continue;
        }
        ll ans = 0;
        ans += *s[1].begin();
        ubd(1, z, mp[*s[1].begin()], -1, 1);
        ans += *(--s[0].end()) * 2;
        ubd(1, z, mp[*(--s[0].end())], -1, 1);
        ll u = qry(1, z, sz(s[1]) - 1, 1);
        ans += u * 2;
        ans += (t[1].se - u);

        printf("%lld\n", ans);

        ubd(1, z, mp[*s[1].begin()], 1, 1);
        ubd(1, z, mp[*(--s[0].end())], 1, 1);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}