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
const int N = 102;
const ll INF = 1000000009000006;

int n;
ll k;
int a[N];

bool stg(ll d)
{
    ll kk = 0;
    for (int i = 1; i <= n; ++i)
    {
        kk += (d - a[i] % d) % d;
    }
    return (kk <= k);
}

void solv()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j * j <= a[i]; ++j)
        {
            if (a[i] % j == 0)
                v.push_back(a[i] / j);
            else
                v.push_back(a[i] / j + 1);
        }
    }
    v.push_back(1);
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (i != v.size() - 1 && v[i] == v[i + 1])
            continue;
        if (stg(v[i]))
        {
            ll ans;
            ll l = v[i];
            ll r;
            if (i != v.size() - 1)
                r = v[i + 1] - 1;
            else
                r = INF;
            while (l <= r)
            {
                ll m = (l + r) / 2;
                if (stg(m))
                {
                    ans = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            printf("%lld\n", ans);
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}