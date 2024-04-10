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
int a[N];

int u[N];
int ans[N][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    /*n = 50;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    for (int i = n; i >= 1; --i)
        swap(a[i], a[rnf() % i + 1]);*/

    for (int i = 1; i <= n; ++i)
    {
        int x = i, y = i;
        ans[x][y] = a[i];
        for (int ii = 0; ii < a[i] - 1; ++ii)
        {
            if (y - 1 >= 1 && !ans[x][y - 1])
            {
                --y;
            }
            else
            {
                ++x;
            }
            assert(!ans[x][y]);
            ans[x][y] = a[i];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
            cout << ans[i][j] << ' ';
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}