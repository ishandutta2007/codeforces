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
const int N = 1000006;

int n, C;
ll a[N];

void solv()
{
    cin >> n >> C;
    for (int i = 1; i <= n; ++i)
    {
        int c, d, h;
        cin >> c >> d >> h;
        a[c] = max(a[c], d * 1LL * h);
    }

    for (int i = 1; i <= C; ++i)
    {
        a[i] = max(a[i], a[i - 1]);
        for (int j = i, k = 1; j <= C; j += i, ++k)
            a[j] = max(a[j], a[i] * k);
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int D;
        ll H;
        cin >> D >> H;
        H *= D;

        int l = 1, r = C;
        int ans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m] > H)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        cout << ans << ' ';
    }
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}