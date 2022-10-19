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

int n;
int a[N][4];

int ans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i][1]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i][2]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i][3]);
    ans[1] = a[1][1];
    for (int i = 2; i <= n; ++i)
    {
        if (i < n)
        {
            for (int j = 1; j <= 3; ++j)
            {
                if (a[i][j] != ans[i - 1])
                {
                    ans[i] = a[i][j];
                    break;
                }
            }
        }
        else
        {
            for (int j = 1; j <= 3; ++j)
            {
                if (a[i][j] != ans[i - 1] && a[i][j] != ans[1])
                {
                    ans[i] = a[i][j];
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}