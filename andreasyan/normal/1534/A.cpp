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
const int N = 55;

int n, m;
char a[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    bool z = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                if (a[i][j] == 'W')
                    z = false;
            }
            else
            {
                if (a[i][j] == 'R')
                    z = false;
            }
        }
    }
    if (z)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if ((i + j) % 2 == 0)
                    cout << 'R';
                else
                    cout << 'W';
            }
            cout << "\n";
        }
        return;
    }

    z = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                if (a[i][j] == 'R')
                    z = false;
            }
            else
            {
                if (a[i][j] == 'W')
                    z = false;
            }
        }
    }
    if (z)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if ((i + j) % 2 == 0)
                    cout << 'W';
                else
                    cout << 'R';
            }
            cout << "\n";
        }
        return;
    }

    cout << "NO\n";
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