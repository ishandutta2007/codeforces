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

void solv()
{
    ll n;
    scanf("%lld", &n);
    ll nn = n;

    vector<pair<ll, ll> > v;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.push_back(m_p(i, 0));
            while (n % i == 0)
            {
                v.back().se++;
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        v.push_back(m_p(n, 1));
    }

    ll maxu = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        maxu = max(maxu, v[i].se);
    }

    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i].se == maxu)
        {
            printf("%lld\n", maxu);
            for (int j = 0; j < maxu - 1; ++j)
            {
                printf("%lld ", v[i].fi);
                nn /= v[i].fi;
            }
            printf("%lld\n", nn);
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
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}