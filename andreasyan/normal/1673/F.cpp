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
const int N = 44;

int t[N][N], s[N][N];

void rec(int x1, int x2, int y1_, int y2, int u)
{
    if (x1 == x2)
    {
        assert(y1_ == y2);
        return;
    }

    assert(u >= 1);
    int mx = (x1 + x2) / 2;
    int my = (y1_ + y2) / 2;

    for (int i = x1; i <= x2; ++i)
        t[i][my] |= (1 << u);

    for (int j = y1_; j <= y2; ++j)
        s[mx][j] |= (1 << (u - 1));

    rec(x1, mx, y1_, my, u - 2);
    rec(x1, mx, my + 1, y2, u - 2);
    rec(mx + 1, x2, y1_, my, u - 2);
    rec(mx + 1, x2, my + 1, y2, u - 2);
}

int n, qq;

void solv()
{
    rec(0, 31, 0, 31, 9);

    /*int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            sum += t[i][j];
            sum += s[i][j];
        }
    }

    cout << sum << "\n";
    return;*/

    cin >> n >> qq;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
            cout << t[i][j] << ' ';
        cout << endl;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << s[i][j] << ' ';
        cout << endl;
    }

    int g = 0;
    while (qq--)
    {
        int gg;
        cin >> gg;
        g ^= gg;

        int cg = g;

        int l = 0, r = 31;
        for (int u = 9; u >= 0; u -= 2)
        {
            int m = (l + r) / 2;
            if (!(g & (1 << u)))
                r = m;
            else
            {
                l = m + 1;
                for (int j = 0; j < n; ++j)
                {
                    if (t[0][j] == (1 << u))
                        break;
                    g ^= t[0][j];
                }
            }
        }
        assert(l == r);
        int y = l;

        l = 0, r = 31;
        for (int u = 8; u >= 0; u -= 2)
        {
            int m = (l + r) / 2;
            if (!(g & (1 << u)))
                r = m;
            else
            {
                l = m + 1;
                for (int i = 0; i < n; ++i)
                {
                    if (s[i][0] == (1 << u))
                        break;
                    g ^= s[i][0];
                }
            }
        }
        assert(l == r);
        int x = l;

        g = cg;

        cout << x + 1 << ' ' << y + 1 << endl;
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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