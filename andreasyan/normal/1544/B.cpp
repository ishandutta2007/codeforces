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
const int N = 25;
const int xx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int yy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int n, m;
bool c[N][N];

void solv()
{
    cin >> n >> m;

    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= m + 1; ++j)
            c[i][j] = false;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!(i == 1 || i == n || j == 1 || j == m))
                continue;
            bool z = false;
            for (int k = 0; k < 8; ++k)
            {
                int hi = i + xx[k];
                int hj = j + yy[k];
                if (c[hi][hj])
                {
                    z = true;
                    break;
                }
            }
            if (!z)
                c[i][j] = true;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << c[i][j];
        }
        cout << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}