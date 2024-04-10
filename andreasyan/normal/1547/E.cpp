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
const int N = 300005, INF = 1200000009;

int n, k;
int a[N], t[N];

int u[N];
int ans[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
        cin >> a[i];
    for (int i = 1; i <= k; ++i)
        cin >> t[i];

    for (int i = 1; i <= n; ++i)
        ans[i] = u[i] = INF;
    for (int i = 1; i <= k; ++i)
        u[a[i]] = t[i];

    int minu = INF;
    for (int i = 1; i <= n; ++i)
    {
        minu = min(minu, u[i]);
        ans[i] = min(ans[i], minu);
        ++minu;
    }

    minu = INF;
    for (int i = n; i >= 1; --i)
    {
        minu = min(minu, u[i]);
        ans[i] = min(ans[i], minu);
        ++minu;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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