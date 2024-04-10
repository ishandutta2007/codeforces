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

int n, m, qq;
int a[N][N];

void solv()
{
    cin >> n >> m >> qq;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }

    while (qq--)
    {
        int x, y;
        x = 1;
        cin >> y;
        while (1)
        {
            if (x == n + 1)
            {
                cout << y << ' ';
                break;
            }
            if (a[x][y] == 1)
            {
                a[x][y] = 2;
                ++y;
            }
            else if (a[x][y] == 2)
                ++x;
            else if (a[x][y] == 3)
            {
                a[x][y] = 2;
                --y;
            }
        }
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
        solv();
    return 0;
}