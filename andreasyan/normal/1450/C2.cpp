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
const int N = 303;

int n;
char a[N][N];

int o[3], x[3];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);

    memset(o, 0, sizeof o);
    memset(x, 0, sizeof x);

    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] != '.')
                ++k;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] != '.')
            {
                if (a[i][j] == 'O')
                    o[(i + j) % 3]++;
                else
                    x[(i + j) % 3]++;
            }
        }
    }

    for (int u1 = 0; u1 < 3; ++u1)
    {
        for (int u2 = 0; u2 < 3; ++u2)
        {
            if (u1 == u2)
                continue;
            if (o[u1] + x[u2] <= k / 3)
            {
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if (a[i][j] == '.')
                        {
                            printf(".");
                            continue;
                        }
                        else
                        {
                            if ((i + j) % 3 == u1)
                                printf("X");
                            else if ((i + j) % 3 == u2)
                                printf("O");
                            else
                                printf("%c", a[i][j]);
                        }
                    }
                    printf("\n");
                }
                return;
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
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}