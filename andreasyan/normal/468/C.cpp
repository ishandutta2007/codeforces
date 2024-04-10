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
const int N = 22;
const ll M = 100000000000000000;

ll dp[N];
ll dpt[N];

ll summ(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

ll sum(ll x)
{
    vector<int> v;
    while (x)
    {
        v.push_back(x % 10);
        x /= 10;
    }

    reverse(all(v));

    for (int i = 0; i < N; ++i)
        dp[i] = dpt[i] = 0;

    ll p = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        for (int u = 0; u < 10; ++u)
        {
            dp[i + 1] += dp[i];
            dpt[i + 1] += dpt[i];
            dp[i + 1] += dpt[i] * u;
            if (u < v[i])
            {
                dp[i + 1] += p;
                dpt[i + 1] += 1;
                dp[i + 1] += u;
            }
        }
        p += v[i];
    }

    return dp[sz(v)] + p;
}

bool c[100][1000];

void solv()
{
    ll a;
    cin >> a;

    ll l = 1, r = M;
    ll u = -1;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (sum(m) >= a)
        {
            u = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    assert(u != -1);

    l = 1;
    r = u;

    ll t = sum(u) - a;
    while (1)
    {
        if (t == 0)
        {
            cout << l << ' ' << r << "\n";
            return;
        }
        if (t > 0)
        {
            t -= summ(l);
            ++l;
        }
        else
        {
            ++r;
            t += summ(r);
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}