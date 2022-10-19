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
const int M = 70;

int n, m;
char a[M];

void solv()
{
    scanf("%d%d", &n, &m);
    vector<ll> v;
    for (int ii = 0; ii < n; ++ii)
    {
        scanf(" %s", a);
        ll x = 0;
        for (int i = 0; i < m; ++i)
        {
            if (a[i] == '1')
                x += (1LL << (m - i - 1));
        }
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<pair<ll, ll> > vv;
    ll u = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        vv.push_back(m_p(u, v[i] - 1));
        u = v[i] + 1;
    }
    vv.push_back(m_p(u, (1LL << m) - 1));
    u = ((1LL << m) - n) / 2 + ((1LL << m) - n) % 2;
    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i].fi > vv[i].se)
            continue;
        if (vv[i].se - vv[i].fi + 1 < u)
            u -= (vv[i].se - vv[i].fi + 1);
        else
        {
            ll ans = vv[i].fi + u - 1;
            for (int i = 0; i < m; ++i)
            {
                if ((ans & (1LL << (m - i - 1))))
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}