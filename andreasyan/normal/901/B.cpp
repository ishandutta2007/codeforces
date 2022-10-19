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
const int N = 152;

int f[N][N];

void solv()
{
    int n;
    scanf("%d", &n);
    f[0][0] = 1;
    f[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= (i - 1); ++j)
            f[i][j + 1] = f[i - 1][j];
        bool z = true;
        for (int j = 0; j <= (i - 2); ++j)
        {
            if (abs(f[i][j] + f[i - 2][j]) > 1)
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            for (int j = 0; j <= (i - 2); ++j)
            {
                f[i][j] += f[i - 2][j];
            }
        }
        else
        {
            for (int j = 0; j <= (i - 2); ++j)
            {
                f[i][j] -= f[i - 2][j];
            }
        }
    }
    printf("%d\n", n);
    for (int i = 0; i <= n; ++i)
        printf("%d ", f[n][i]);
    printf("\n");
    printf("%d\n", n - 1);
    for (int i = 0; i <= (n - 1); ++i)
        printf("%d ", f[n - 1][i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}