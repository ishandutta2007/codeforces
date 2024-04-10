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
const int N = 1103;

int n, m;
char s[N], t[N];

bool c[N][N];

void solv()
{
    cin >> s >> t;

    n = strlen(s);
    m = strlen(t);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            c[i][j] = true;
            for (int k = j; k < m; ++k)
            {
                if (i - (k - j + 1) < 0)
                {
                    c[i][j] = false;
                    break;
                }
                if (s[i - (k - j + 1)] != t[k])
                {
                    c[i][j] = false;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[j] != t[(j - i)])
                break;
            if ((j - i) == m - 1)
            {
                cout << "YES\n";
                return;
            }
            if (c[j][(j - i + 1)])
            {
                cout << "YES\n";
                return;
            }
        }
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