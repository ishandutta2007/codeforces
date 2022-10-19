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

int n;
int a[3][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            a[i][j] -= x;
        }
    }

    int s = 0;
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
            s += a[i][j];
    }
    if (s)
    {
        cout << "-1\n";
        return;
    }

    int t = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        t += a[1][i];
        s += a[2][i];
        if (s > 0 && t < 0)
        {
            int minu = min(s, -t);
            s -= minu;
            t += minu;
            ans += minu;
        }
        if (s < 0 && t > 0)
        {
            int minu = min(-s, t);
            s += minu;
            t -= minu;
            ans += minu;
        }
        ans += abs(s);
        ans += abs(t);
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}