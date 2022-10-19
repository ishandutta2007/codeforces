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
const int N = 2003;

int n;
int dl[N], dr[N];

bool dp[N][N];
int p[N][N];

int m;
char ans[N];
void rec(int l, int r)
{
    if (l > r)
        return;
    ans[m++] = '(';
    rec(l + 1, l + (p[l][r] - 1) / 2);
    ans[m++] = ')';
    rec(l + (p[l][r] - 1) / 2 + 1, r);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &dl[i], &dr[i]);
    for (int l = 1; l <= n + 1; ++l)
        dp[l][l - 1] = true;
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            for (int i = dl[l]; i <= dr[l]; ++i)
            {
                if (i % 2 == 0)
                    continue;
                if (dp[l + 1][l + (i - 1) / 2] && dp[l + (i - 1) / 2 + 1][r])
                {
                    dp[l][r] = true;
                    p[l][r] = i;
                    break;
                }
            }
        }
    }

    if (!dp[1][n])
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    rec(1, n);
    printf("%s\n", ans);
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