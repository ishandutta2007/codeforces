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
const ll M = 1000000007;

ll ans;

int n, m;
vector<pair<int, ll> > g[N];

const int l = 60;
ll u[l];
int q[l][2];

void ave(ll x)
{
    for (int i = l - 1; i >= 0; --i)
    {
        if ((x & (1LL << i)))
        {
            if (!u[i])
            {
                u[i] = x;
                return;
            }
            x ^= u[i];
        }
    }
}

bool c[N];
ll d[N];
void dfs0(int x, int p)
{
    c[x] = true;
    for (int i = 0; i < l; ++i)
    {
        if ((d[x] & (1LL << i)))
            q[i][1]++;
        else
            q[i][0]++;
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (!c[h])
        {
            d[h] = (d[x] ^ g[x][i].se);
            dfs0(h, x);
        }
        else if (h != p)
        {
            ave((d[x] ^ d[h] ^ g[x][i].se));
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        ll z;
        scanf("%d%d%lld", &x, &y, &z);
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            for (int i = 0; i < l; ++i)
            {
                q[i][0] = q[i][1] = 0;
                u[i] = 0;
            }
            dfs0(x, x);

            int r = 0;
            ll uu = 0;
            for (int i = 0; i < l; ++i)
            {
                if (u[i])
                    ++r;
                uu |= u[i];
            }
            int qq = q[0][0] + q[0][1];
            for (int i = 0; i < l; ++i)
            {
                if ((uu & (1LL << i)))
                    ans +=  (1LL << (r - 1)) % M * ((1LL << i) % M) % M * ((qq * 1LL * (qq - 1) / 2) % M) % M;
                else
                    ans += (1LL << r) % M * ((1LL << i) % M) % M * ((q[i][0] * 1LL * q[i][1]) % M) % M;
                ans %= M;
            }
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}