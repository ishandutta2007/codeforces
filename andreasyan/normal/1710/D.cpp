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
const int N = 2003;

int n;
char a[N][N];

int p[N];
int ul[N], ur[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
    ul[y] = min(ul[y], ul[x]);
    ur[y] = max(ur[y], ur[x]);
}

vector<int> g[N];
void dfs(int x, int p, int l, int r, int& q)
{
    ++q;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (!(l <= h && h <= r))
            continue;
        dfs(h, x, l, r, q);
    }
}

bool stg(int l, int r)
{
    int q = 0;
    dfs(l, l, l, r, q);
    return ((r - l + 1) == q);
}

void solv()
{
    cin >> n;
    for (int l = 1; l <= n; ++l)
    {
        cin >> (a[l] + l);
        for (int r = l; r <= n; ++r)
            a[l][r] -= '0';
    }

    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        ul[i] = ur[i] = i;
        g[i].clear();
    }

    vector<pair<int, int> > b;
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (!a[l][r])
                continue;
            vector<int> v;
            int i = l;
            while (1)
            {
                v.push_back(i);
                if (fi(i) == fi(r))
                {
                    break;
                }
                i = ur[fi(i)] + 1;
            }
            v.pop_back();
            v.push_back(r);
            assert(sz(v) != 3);

            if (sz(v) == 1)
                continue;
            if (sz(v) == 2)
            {
                b.push_back(m_p(v[0], v[1]));
            }
            else
            {
                for (int i = 2; i < sz(v); ++i)
                    b.push_back(m_p(v[0], v[i]));
                b.push_back(m_p(v[1], v.back()));
            }
            for (int i = 1; i < sz(v); ++i)
                kpc(v[0], v[i]);
        }
    }

    assert(sz(b) == n - 1);
    for (int i = 0; i < n - 1; ++i)
        cout << b[i].fi << ' ' << b[i].se << "\n";

    return;
    for (int i = 0; i < n - 1; ++i)
    {
        int x = b[i].fi;
        int y = b[i].se;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
        {
            assert(a[l][r] == stg(l, r));
        }
    }
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