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
const int N = 202;

int n, m;
int a[N][N];

int t[N], s[N];

bool stg()
{
    int qq[2] = {};
    for (int i = 1; i <= n; ++i)
    {
        int q = 0;
        for (int j = 1; j < m; ++j)
        {
            if ((a[i][j] ^ s[j]) != (a[i][j + 1] ^ s[j + 1]))
                ++q;
        }
        if (q >= 2)
            return false;
        ++qq[q];
    }
    if (qq[1] > 1)
        return false;
    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        int q = 0;
        for (int j = 1; j < m; ++j)
        {
            if ((a[i][j] ^ s[j]) != (a[i][j + 1] ^ s[j + 1]))
                ++q;
        }
        if (q == 0)
        {
            if (!z)
            {
                if ((a[i][1] ^ s[1]) == 0)
                    t[i] = 0;
                else
                    t[i] = 1;
            }
            else
            {
                if ((a[i][1] ^ s[1]) == 1)
                    t[i] = 0;
                else
                    t[i] = 1;
            }
        }
        else
        {
            z = true;
            if ((a[i][1] ^ s[1]) == 0)
                t[i] = 0;
            else
                t[i] = 1;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d", t[i]);
    printf("\n");
    for (int j = 1; j <= m; ++j)
        printf("%d", s[j]);
    printf("\n");
    return true;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int j = 1; j <= m; ++j)
    {
        if (a[1][j] == 0)
            s[j] = 0;
        else
            s[j] = 1;
    }
    if (stg())
    {
        return;
    }
    for (int j = 1; j <= m; ++j)
    {
        if (a[1][j] == 1)
            s[j] = 0;
        else
            s[j] = 1;
    }
    if (stg())
    {
        return;
    }
    for (int j = 1; j <= m; ++j)
    {
        if (a[n][j] == 0)
            s[j] = 0;
        else
            s[j] = 1;
    }
    if (stg())
    {
        return;
    }
    for (int j = 1; j <= m; ++j)
    {
        if (a[n][j] == 1)
            s[j] = 0;
        else
            s[j] = 1;
    }
    if (stg())
    {
        return;
    }
    printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}