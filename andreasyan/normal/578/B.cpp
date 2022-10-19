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

int n, k, x;
ll a[N];

ll p[N], s[N];

void solv()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] | a[i]);
    for (int i = n; i >= 1; --i)
        s[i] = (s[i + 1] | a[i]);

    ll xk = 1;
    for (int i = 0; i < k; ++i)
        xk *= x;

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll yans = (p[i - 1] | s[i + 1] | (a[i] * xk));
        ans = max(ans, yans);
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

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(12);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}