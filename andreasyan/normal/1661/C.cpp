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
const int N = 300005;

int n;
int a[N];
int b[N];

bool stg(ll d)
{
    ll q1 = (d + 1) / 2;
    ll q2 = d / 2;

    for (int i = 1; i <= n; ++i)
        b[i] = a[i];

    for (int i = 1; i <= n; ++i)
    {
        if ((b[n] - b[i]) / 2 <= q2)
        {
            q2 -= (b[n] - b[i]) / 2;
            b[i] += ((b[n] - b[i]) / 2) * 2;
        }
        else
        {
            b[i] += q2 * 2;
            q2 = 0;
        }
    }

    for (int i = 1; i <= n; ++i)
        q1 -= (b[n] - b[i]);
    if (q1 >= 0)
        return true;

    q1 = (d + 1) / 2;
    ++b[n];
    --q1;
    for (int i = 1; i <= n; ++i)
    {
        if ((b[n] - b[i]) / 2 <= q2)
        {
            q2 -= (b[n] - b[i]) / 2;
            b[i] += ((b[n] - b[i]) / 2) * 2;
        }
        else
        {
            b[i] += q2 * 2;
            q2 = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
        q1 -= (b[n] - b[i]);
    return (q1 >= 0);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    ll l = 0, r = n * 2000000000LL;
    ll ans = 0;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
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