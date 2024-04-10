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
const int N = 503;

int n;
int a[N][N];

ll solvv(int x1, int x2, int y1_, int y2)
{
    ll ans;

    ll yans = 0;
    yans = a[x1][y1_];
    /*for (int i = x1; i <= x2; ++i)
    {
        yans += a[i][y1_];
    }*/
    ans = yans;

    yans = 0;
    /*for (int i = x1; i <= x2; ++i)
    {
        yans += a[i][y2];
    }*/
    yans = a[x1][y2];
    ans = min(ans, yans);

    yans = 0;
    /*for (int j = y1_; j <= y2; ++j)
    {
        yans += a[x1][j];
    }*/
    yans = a[x2][y1_];
    ans = min(ans, yans);

    yans = 0;
    /*for (int j = y1_; j <= y2; ++j)
    {
        yans += a[x2][j];
    }*/
    yans = a[x2][y2];
    ans = min(ans, yans);

    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n * 2; ++i)
    {
        for (int j = 1; j <= n * 2; ++j)
        {
            cin >> a[i][j];
        }
    }

    ll ans = min(solvv(1, n, n + 1, n * 2), solvv(n + 1, n * 2, 1, n));

    for (int i = n + 1; i <= n * 2; ++i)
    {
        for (int j = n + 1; j <= n * 2; ++j)
        {
            ans += a[i][j];
        }
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