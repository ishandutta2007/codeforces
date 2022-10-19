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
const int N = 40004, M = 1000000000;

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

bool c[N];
vector<int> pv;
void pre()
{
    c[0] = c[1] = true;
    for (int i = 2; i * i <= M; ++i)
    {
        if (c[i])
            continue;
        pv.push_back(i);
        for (int j = i * i; j * 1LL * j <= M; j += i)
            c[j] = true;
    }
}

ll qry(ll x)
{
    printf("? %lld\n", x);
    fflush(stdout);
    ll ans = gcd(x, 2 * 3 * 5);
    scanf("%lld", &ans);
    return ans;
}

void solv()
{
    ll u = 1;
    vector<int> uv;
    vector<int> in;
    ll maxu = M * 1LL * M;
    int h = 22;
    for (int i = 0; ; ++i)
    {
        if ((in.size() / 2 + in.size() % 2) + 1 >= h)
            break;
        if (pv[i] <= (M * 1LL * M) / u)
        {
            u *= pv[i];
            uv.push_back(pv[i]);
        }
        else
        {
            ll x = qry(u);
            --h;
            for (int i = 0; i < uv.size(); ++i)
            {
                if (x % uv[i] == 0)
                {
                    in.push_back(uv[i]);
                }
            }
            u = 1;
            uv.clear();
            u *= pv[i];
            uv.push_back(pv[i]);
        }
    }
    int ans = 1;
    u = 1;
    uv.clear();
    for (int i = 0; i < in.size(); ++i)
    {
        ll uu = 1;
        while (uu * in[i] <= M)
            uu *= in[i];
        uu /= in[i];
        if (u <= (M * 1LL * M) / uu)
        {
            u *= uu;
            uv.push_back(in[i]);
        }
        else
        {
            ll x = qry(u);
            for (int i = 0; i < uv.size(); ++i)
            {
                int q = 0;
                while (x % uv[i] == 0)
                {
                    ++q;
                    x /= uv[i];
                }
                ans *= (q + 1);
            }
            u = 1;
            uv.clear();
            u *= uu;;
            uv.push_back(in[i]);
        }
    }
    if (u > 1)
    {
        ll x = qry(u);
        for (int i = 0; i < uv.size(); ++i)
        {
            int q = 0;
            while (x % uv[i] == 0)
            {
                ++q;
                x /= uv[i];
            }
            ans *= (q + 1);
        }
        u = 1;
        uv.clear();
    }
    ans = max(ans + 7, ans * 2);
    printf("! %d\n", ans);
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}