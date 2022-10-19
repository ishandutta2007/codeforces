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
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n;
char a[N][N];

bool c[N][N];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            c[i][j] = false;
        }
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = n; j >= 1; --j)
        {
            if (a[i][j] != '1')
                continue;
            if (i == n || j == n)
            {
                c[i][j] = true;
                continue;
            }
            if (c[i + 1][j] || c[i][j + 1])
                c[i][j] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == '1' && !c[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}