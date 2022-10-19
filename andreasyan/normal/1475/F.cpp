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

int n;
char a[N][N], b[N][N];

bool c[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (b[i] + 1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            c[i][j] = ((a[i][j] - '0') ^ (b[i][j] - '0'));
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (c[i][1])
        {
            for (int j = 1; j <= n; ++j)
            {
                c[i][j] ^= true;
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            if (c[i][j] != c[1][j])
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}