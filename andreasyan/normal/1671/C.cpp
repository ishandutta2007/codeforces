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
const int N = 200005;

int n, x;
int a[N];

ll p[N];

void solv()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    ll ans = 0;
    ll d = 0;
    for (int i = n; i >= 1; --i)
    {
        int l = 1, r = 1000000009;
        int q = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[i] + (d + m - 1) * i <= x)
            {
                q = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        ans += q * 1LL * i;
        d += q;
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