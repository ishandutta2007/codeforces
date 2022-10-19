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

int n, k;
bool c[N][N];

void solv()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            c[i][j] = false;
        }
    }

    if (k <= n / 2 + n % 2)
    {
        for (int i = 1, j = 0; j < k; i += 2, ++j)
        {
            c[i][i] = true;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (c[i][j])
                    cout << 'R';
                else
                    cout << '.';
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "-1\n";
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