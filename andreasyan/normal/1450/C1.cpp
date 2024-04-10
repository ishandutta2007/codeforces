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
const int N = 302;

int n;
char a[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);

    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 'X')
                ++q;
        }
    }

    int u[3] = {0, 1, 2};
    do
    {
        int qq = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == 'X' && (j % 3) == u[(i % 3)])
                    ++qq;
            }
        }
        if (qq <= q / 3)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (a[i][j] == 'X' && (j % 3) == u[(i % 3)])
                        a[i][j] = 'O';
                }
            }
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    putchar(a[i][j]);
                putchar('\n');
            }
            return;
        }
    } while (next_permutation(u, u + 3));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}