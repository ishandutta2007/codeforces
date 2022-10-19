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
const int N = 102;

int n, m;
char a[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    if (a[1][1] == '1')
    {
        cout << "-1\n";
        return;
    }

    int q = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            q += (a[i][j] - '0');

    cout << q << "\n";
    for (int i = n; i >= 1; --i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (a[i][j] == '1')
            {
                if (i > 1)
                    cout << i - 1 << ' ' << j << ' ' << i << ' ' << j << "\n";
                else
                {
                    assert(j > 1);
                    cout << i << ' ' << j - 1 << ' ' << i << ' ' << j << "\n";
                }
            }
        }
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