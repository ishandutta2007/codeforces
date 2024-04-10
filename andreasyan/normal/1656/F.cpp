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
const int N = 200005, T = 1000006;
const ll INF = 1000000009000000009;

int n;
int a[N];

ll ans;

ll U(int x, int y, int t)
{
    return x * 1LL * y + t * 1LL * (x + y);
}

ll stg(int t)
{
    ll yans = 0;

    int l = 2, r = n;
    int minu = a[1];
    int maxu = a[1];
    while (l <= r)
    {
        ll g = min(min(U(minu, a[l], t), U(minu, a[r], t)), min(U(maxu, a[l], t), U(maxu, a[r], t)));
        yans += g;

        if (g == U(minu, a[l], t) || g == U(maxu, a[l], t))
        {
            minu = min(minu, a[l]);
            maxu = max(maxu, a[l]);
            ++l;
        }
        else
        {
            minu = min(minu, a[r]);
            maxu = max(maxu, a[r]);
            --r;
        }
    }

    ans = max(ans, yans);
    return yans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    ans = -INF;

    int l = -T, r = T;
    while ((r - l) > 5)
    {
        int m = (l + r) / 2;
        if (stg(m) < stg(m + 1))
        {
            l = m;
        }
        else
        {
            r = m + 1;
        }
    }

    for (int t = l; t <= r; ++t)
        stg(t);

    ll fans = ans;
    stg(T + 1);
    stg(-T - 1);
    if (ans != fans)
    {
        cout << "INF\n";
        return;
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}