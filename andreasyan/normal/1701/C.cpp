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

int n, m;
int q[N];

bool stg(int t)
{
    ll w = 0;
    ll p = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] <= t)
        {
            w += (t - q[i]) / 2;
        }
        else
        {
            p += (q[i] - t);
        }
    }
    return (w >= p);
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        q[i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        ++q[x];
    }

    int l = 1, r = m * 2;
    int ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (stg(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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