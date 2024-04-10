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

int p[N], s[N];

void solv()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int maxu = a[1];
    int minu = a[1];
    for (int i = 1; i <= n; ++i)
    {
        maxu = max(maxu, a[i]);
        minu = min(minu, a[i]);
    }

    ll ans = 0;
    for (int i = 1; i < n; ++i)
        ans += abs(a[i + 1] - a[i]);

    if (minu <= 1 && x <= maxu)
    {
        cout << ans << "\n";
        return;
    }
    if (minu <= 1)
    {
        int pans = min(abs(x - a[1]), abs(x - a[n]));
        for (int i = 1; i < n; ++i)
        {
            pans = min(pans, abs(x - a[i]) + abs(x - a[i + 1]) - abs(a[i] - a[i + 1]));
        }
        cout << ans + pans << "\n";
        return;
    }
    if (x <= maxu)
    {
        int pans = min(abs(1 - a[1]), abs(1 - a[n]));
        for (int i = 1; i < n; ++i)
        {
            pans = min(pans, abs(1 - a[i]) + abs(1 - a[i + 1]) - abs(a[i] - a[i + 1]));
        }
        cout << ans + pans << "\n";
        return;
    }

    int pans = x - 1 + min(abs(a[1] - x), abs(a[1] - 1));
    pans = min(pans, x - 1 + min(abs(a[n] - x), abs(a[n] - 1)));
    for (int i = 1; i < n; ++i)
    {
        pans = min(pans, x - 1 + min(abs(a[i] - x) + abs(a[i + 1] - 1), abs(a[i] - 1) + abs(a[i + 1] - x)) - abs(a[i + 1] - a[i]));
    }

    p[0] = abs(a[1] - 1);
    for (int i = 1; i < n; ++i)
        p[i] = min(p[i - 1], abs(1 - a[i]) + abs(1 - a[i + 1]) - abs(a[i] - a[i + 1]));

    s[n] = abs(a[n] - x);
    for (int i = n - 1; i >= 1; --i)
        s[i] = min(s[i + 1], abs(x - a[i]) + abs(x - a[i + 1]) - abs(a[i] - a[i + 1]));

    for (int i = 0; i < n; ++i)
        pans = min(pans, p[i] + s[i + 1]);

    p[0] = abs(a[1] - x);
    for (int i = 1; i < n; ++i)
        p[i] = min(p[i - 1], abs(x - a[i]) + abs(x - a[i + 1]) - abs(a[i] - a[i + 1]));

    s[n] = abs(a[n] - 1);
    for (int i = n - 1; i >= 1; --i)
        s[i] = min(s[i + 1], abs(1 - a[i]) + abs(1 - a[i + 1]) - abs(a[i] - a[i + 1]));

    for (int i = 0; i < n; ++i)
        pans = min(pans, p[i] + s[i + 1]);

    cout << ans + pans << "\n";
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