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

int m, n;
int a[N], b[N];

vector<pair<int, pair<int, int> > > v;

int p[N];
int fi(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

void solv()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= m; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int j;
            scanf("%d", &j);
            v.push_back(m_p(a[i] + b[j], m_p(i, m + j)));
        }
    }

    for (int i = 1; i <= n + m; ++i)
        p[i] = i;
    ll ans = 0;
    sort(all(v));
    reverse(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i].se.fi;
        int y = v[i].se.se;
        if (fi(x) != fi(y))
        {
            kpc(x, y);
        }
        else
        {
            ans += v[i].fi;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}