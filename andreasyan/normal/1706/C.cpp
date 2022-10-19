#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 100005;

int n;
int a[N];

int u[N];
int ans[N];

ll p[N], s[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i <= n + 1; ++i)
    {
        p[i] = s[i] = 0;
    }

    for (int i = 2; i < n; ++i)
    {
        p[i] = p[i - 2] + max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]);
    }
    for (int i = n - 1; i > 1; --i)
    {
        s[i] = s[i + 2] + max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]);
    }

    if (n % 2 == 1)
    {
        cout << p[n - 1] << "\n";
        return;
    }

    ll ans = min(p[n - 1], s[2]);
    for (int i = 2; i <= n - 2; i += 2)
    {
        ans = min(ans, p[i] + s[i + 3]);
    }

    cout << ans << "\n";
}

int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}