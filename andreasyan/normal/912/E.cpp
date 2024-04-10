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
const int N = 18;
const ll M = 1000000009000000009;

int n;
int a[N];

ll k;

vector<ll> v1, v2;

ll stg(ll x)
{
    ll ans = 0;
    int j = v2.size() - 1;
    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1[i] > x)
            break;
        while (v1[i] > (double)x / v2[j])
            --j;
        ans += (j + 1);
    }
    return ans;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%lld", &k);
    int si = n + 1;
    v1.push_back(1);
    for (int i = 1; i <= n; ++i)
    {
        vector<ll> v;
        for (int j = 0; j < v1.size(); ++j)
        {
            ll x = v1[j];
            while (1)
            {
                v.push_back(x);
                if (x > (double)M / a[i])
                    break;
                x *= a[i];
            }
        }
        v1 = v;
        if (v1.size() > 1000000)
        {
            si = i + 1;
            break;
        }
    }
    v2.push_back(1);
    for (int i = si; i <= n; ++i)
    {
        vector<ll> v;
        for (int j = 0; j < v2.size(); ++j)
        {
            ll x = v2[j];
            while (1)
            {
                v.push_back(x);
                if (x > (double)M / a[i])
                    break;
                x *= a[i];
            }
        }
        v2 = v;
    }
    sort(all(v1));
    sort(all(v2));
    ll l = 1, r = M;
    ll ans;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (stg(m) >= k)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%lld\n", ans);
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