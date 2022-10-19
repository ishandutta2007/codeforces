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
const int N = 33;

int n;
int a[N], b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    ll dp0 = 0, dp1 = 0;
    for (int i = 2; i <= n; ++i)
    {
        ll ndp0 = min(dp0 + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]),
                       dp1 + abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));

        ll ndp1 = min(dp0 + abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]),
                       dp1 + abs(b[i] - b[i - 1]) + abs(a[i] - a[i - 1]));

        dp0 = ndp0;
        dp1 = ndp1;
    }

    cout << min(dp0, dp1) << "\n";
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