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

ll n;
ll s;

ll mins(ll k)
{
    ll s = 0;
    ll ast = 1;
    ll mn = ast;
    ll d = 1;
    for (int i = 1; i <= n; ++i)
    {
        s += d;
        --mn;
        if (mn == 0)
        {
            ast *= k;
            mn = ast;
            d = d + 1;
        }
    }
    return s;
}

ll q[N];

vector<int> v[N];
int ans[N];

void solv()
{
    scanf("%lld%lld", &n, &s);

    if ((n * (n + 1)) / 2 < s)
    {
        printf("No\n");
        return;
    }
    if (mins(n - 1) > s)
    {
        printf("No\n");
        return;
    }

    ll k;

    ll l = 1, r = n - 1;
    //while (k > 1 && mins(k - 1) <= s)
    //    --k;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (mins(m) <= s)
        {
            k = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    q[1] = 1;
    ll ys = 1;
    ll p = 1;
    for (int i = 2; i <= n; ++i)
    {
        ll l = 0, r = q[i - 1] * k;
        q[i] = 0;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            if (ys + m * i <= s && p + m <= n && ys + m * i + ((i + 1) + (i + (n - (p + m)))) * (n - (p + m)) / 2 >= s)
            {
                q[i] = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        ys += q[i] * i;
        p += q[i];
    }

    int z = 0;
    v[1].push_back(++z);
    for (int i = 2; i <= n; ++i)
    {
        int u = 0;
        int mn = k;
        for (int j = 1; j <= q[i]; ++j)
        {
            ans[++z] = v[i - 1][u];
            v[i].push_back(z);
            --mn;
            if (mn == 0)
            {
                ++u;
                mn = k;
            }
        }
    }

    printf("Yes\n");
    for (int i = 2; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
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