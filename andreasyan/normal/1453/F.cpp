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
const int N = 3103;

int n;
int a[N];

/*int t[N][N * 4];
int laz[N][N * 4];

void shi(int ti, int pos)
{
    if (laz[ti][pos] == 0)
        return;
    t[ti][pos * 2] += laz[ti][pos];
    t[ti][pos * 2 + 1] += laz[ti][pos];
    laz[ti][pos * 2] += laz[ti][pos];
    laz[ti][pos * 2 + 1] += laz[ti][pos];
    laz[ti][pos] = 0;
}

void ubd1(int ti, int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[ti][pos] = min(t[ti][pos], y);
        return;
    }
    shi(ti, pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd1(ti, tl, m, x, y, pos * 2);
    else
        ubd1(ti, m + 1, tr, x, y, pos * 2 + 1);
    t[ti][pos] = min(t[ti][pos * 2], t[ti][pos * 2 + 1]);
}

void ubd2(int ti, int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[ti][pos]++;
        laz[ti][pos]++;
        return;
    }
    shi(ti, pos);
    int m = (tl + tr) / 2;
    ubd2(ti, tl, m, l, min(m, r), pos * 2);
    ubd2(ti, m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[ti][pos] = min(t[ti][pos * 2], t[ti][pos * 2 + 1]);
}

int qry(int ti, int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N * N;
    if (tl == l && tr == r)
        return t[ti][pos];
    shi(ti, pos);
    int m = (tl + tr) / 2;
    return min(qry(ti, tl, m, l, min(m, r), pos * 2),
               qry(ti, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}*/

int s[N][N];
int dp[N];
int t[N];
void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    /*for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= (n + 5) * 4; ++j)
        {
            t[i][j] = N * N;
            laz[i][j] = 0;
        }
    }

    ubd1(n, 1, n + 1, n + 1, 0, 1);*/
    for (int i = 1; i <= n; ++i)
        t[i] = 0;
    for (int j2 = n + 1; j2 >= 1; --j2)
        s[n][j2] = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        /*for (int j1 = i; j1 <= n; ++j1)
        {
            for (int j2 = j1 + 1; j2 <= n + 1; ++j2)
            {
                dp[i - 1][j1][j2] = min(dp[i - 1][j1][j2], dp[i][j1][j2] + 1);
                if (i - 1 + a[i - 1] < j1)
                    dp[i - 1][j1][j2] = min(dp[i - 1][j1][j2], dp[i][j1][j2]);
                else if (i - 1 + a[i - 1] < j2)
                    dp[i - 1][i - 1][j1] = min(dp[i - 1][i - 1][j1], dp[i][j1][j2]);
            }
        }*/

        int x = i + a[i];

        for (int j2 = 1; j2 <= n + 1; ++j2)
            dp[j2] = N * N;
        for (int j1 = i + 1; j1 <= x; ++j1)
            dp[j1] = min(dp[j1], s[j1][x + 1] + t[j1]);
        for (int j1 = i + 1; j1 <= x; ++j1)
            t[j1]++;

        s[i][n + 1] = dp[n + 1];
        for (int j2 = n; j2 >= 1; --j2)
            s[i][j2] = min(s[i][j2 + 1], dp[j2]);
    }

    printf("%d\n", s[1][1] + t[1]);
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
    {
        solv();
    }
    return 0;
}