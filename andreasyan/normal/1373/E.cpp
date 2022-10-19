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
const int N = 155;
const ll INF = 1000000009000000009;

void por()
{
    int q = 0;
    for (int i = 1; ; ++i)
    {
        q += 9;
        if (q >= 150)
        {
            printf("%d\n", i);
            return;
        }
    }
}

int f(ll x)
{
    int ans = 0;
    while (x)
    {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

ll anss[N];
ll ans1[10][10][N];

void pre()
{
    for (int n = 1; n < N; ++n)
    {
        if (n % 2 == 0)
        {
            anss[n] = -1;
            continue;
        }
        else if (n <= 30)
        {
            for (ll s = 0; ; ++s)
            {
                if (f(s) + f(s + 1) == n)
                {
                    anss[n] = s;
                    break;
                }
            }
        }
        else
        {
            ll x = anss[n - 2];
            vector<int> v;
            while (x)
            {
                v.push_back(x % 10);
                x /= 10;
            }
            if (v.back() < 9)
                ++v.back();
            else
                v.push_back(1);
            for (int i = v.size() - 1; i >= 0; --i)
            {
                anss[n] = (anss[n] * 10 + v[i]);
            }
        }
    }
    for (int qs = 1; qs < 10; ++qs)
    {
        for (int qb = 1; qb < 10; ++qb)
        {
            for (int n = 0; n <= 150; ++n)
            {
                ans1[qs][qb][n] = -1;
                for (int i = 1; i < N; ++i)
                {
                    ll s = anss[i];
                    if (s == -1)
                        continue;
                    if (f(s) * qs + f(s + 1) * qb == n)
                    {
                        ans1[qs][qb][n] = s;
                        break;
                    }
                }
                //printf("%d %d %d %d\n", qs, qb, n, ans1[qs][qb][n]);
            }
        }
    }
}

void solv()
{
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = INF;
    for (int t = 0; t <= 9; ++t)
    {
        int s = 0;
        int qs = 0, qb = 0;
        for (int i = 0; i <= k; ++i)
        {
            if ((t + i) < 10)
                ++qs;
            else
                ++qb;
            s += f((t + i) % 10);
        }
        if (!qb)
        {
            if (n - s >= 0 && (n - s) % (k + 1) == 0)
            {
                int u = (n - s) / (k + 1);
                ll yans = 0;
                yans = (u % 9);
                for (int i = 0; i < (u / 9); ++i)
                    yans = (yans * 10 + 9);
                yans *= 10;
                yans += t;
                ans = min(ans, yans);
            }
        }
        else
        {
            if (n - s >= 0 && ans1[qs][qb][n - s] != -1)
            {
                ll yans = ans1[qs][qb][n - s];
                yans *= 10;
                yans += t;
                ans = min(ans, yans);
            }
        }
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}