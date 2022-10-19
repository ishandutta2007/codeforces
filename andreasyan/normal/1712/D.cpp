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

int n, k;
int a[N];
int ca[N];

bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
        a[i] = ca[i];
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] * 2 < x)
        {
            a[i] = 1000000000;
            ++q;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (min(a[i], a[i + 1]) >= x)
            return (q <= k);
    }
    for (int i = 1; i < n; ++i)
    {
        if (max(a[i], a[i + 1]) >= x)
            return ((q + 1) <= k);
    }
    return ((q + 2) <= k);
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        ca[i] = a[i];

    int l = 1, r = 1000000000;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
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