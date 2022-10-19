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
const int N = 1003;
const int xx[4] = {0, 0, -1, 1};
const int yy[4] = {-1, 1, 0, 0};

int n;
int b[N][N];

bool c[N][N];
int a[N][N];
bool rec(int x, int y)
{
    if (x == n + 1)
    {
        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == 0)
                {
                    z = false;
                    break;
                }
            }
            if (!z)
                break;
        }
        if (z)
        {
            /*for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    cout << c[i][j];
                }
                cout << "\n";
            }*/
            return true;
        }
        return false;
    }

    for (int j = 1; j <= n; ++j)
    {
        if (x - 2 >= 1 && a[x - 2][j] == 0)
            return false;
    }

    c[x][y] = false;
    if (y < n)
    {
        if (rec(x, y + 1))
            return true;
    }
    else
    {
        if (rec(x + 1, 1))
            return true;
    }

    c[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (1 <= hx && hx <= n && 1 <= hy && hy <= n)
            a[hx][hy] ^= 1;
    }

    if (y < n)
    {
        if (rec(x, y + 1))
            return true;
    }
    else
    {
        if (rec(x + 1, 1))
            return true;
    }

    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (1 <= hx && hx <= n && 1 <= hy && hy <= n)
            a[hx][hy] ^= 1;
    }

    return false;
}

int ans[N][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> b[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = ans[i][j] = c[i][j] = 0;

    int cn = n;

    int l = 1, r = n;
    while ((r - l + 1) >= 16)
    {
        for (int j = l; j <= r; ++j)
            ans[l + 1][j] = ans[r][j] = 1;
        for (int j = l + 1; j <= r - 1; ++j)
            ans[l + 2][j] = ans[r - 1][j] = 1;

        for (int i = l + 3; i < r - 1; i += 2)
            ans[i][l] = ans[i][l + 1] = ans[i][r] = ans[i][r - 1] = 1;
        for (int i = l + 4; i < r - 1; i += 2)
            ans[i][l + 1] = ans[i][l + 2] = ans[i][r - 1] = ans[i][r - 2] = 1;

        l += 4;
        r -= 4;
    }

    n = r - l + 1;
    assert(rec(1, 1));
    n = cn;

    for (int i = l; i <= r; ++i)
    {
        for (int j = l; j <= r; ++j)
        {
            ans[i][j] = c[i - l + 1][j - l + 1];
        }
    }

    int yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (ans[i][j])
                yans ^= b[i][j];
        }
    }

    cout << yans << "\n";

    return;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }
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