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
#define int long long

void solv()
{
    int a, b;
    cin >> a >> b;

    int ca = a, cb = b;

    int ans = b - a;
    for (int q = 0; q < ans; ++q)
    {
        a = ca + q;
        b = cb;

        int minu = a + (a | b);
        for (int i = 0; i < 30; ++i)
        {
            if (!(b & (1 << i)))
            {
                b |= (1 << i);
                minu = min(minu, a + (a | b));
            }
            b ^= (1 << i);
        }

        ans = min(ans, minu + (1 - ca - cb));
    }

    cout << ans << "\n";
}

int32_t main()
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