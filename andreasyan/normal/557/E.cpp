#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003;

int n;
char aa[N], a[N];
int k;

bool dp[N][N];

int z;
int t[N * N][2];
int q[N * N];

int qq[N * N];

void dfs0(int x)
{
    qq[x] = q[x];
    if (t[x][0])
        dfs0(t[x][0]);
    if (t[x][1])
        dfs0(t[x][1]);
    if (t[x][0])
        q[x] += q[t[x][0]];
    if (t[x][1])
        q[x] += q[t[x][1]];
}

int m;
char ans[N];

void solv()
{
    scanf(" %s", aa);
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];
    scanf("%d", &k);
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (l == r)
            {
                dp[l][r] = true;
                continue;
            }
            if (a[l] == a[r] && (l + 2 > r - 2 || dp[l + 2][r - 2]))
                dp[l][r] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int pos = 0;
        for (int j = i; j <= n; ++j)
        {
            if (!t[pos][a[j] - 'a'])
                t[pos][a[j] - 'a'] = ++z;
            pos = t[pos][a[j] - 'a'];
            if (dp[i][j])
                ++q[pos];
        }
    }
    dfs0(0);
    assert(k <= q[0]);
    int pos = 0;
    while (1)
    {
        if (k <= qq[pos])
        {
            printf("%s\n", ans);
            return;
        }
        k -= qq[pos];
        if (t[pos][0])
        {
            if (k <= q[t[pos][0]])
            {
                ans[m++] = 'a';
                pos = t[pos][0];
            }
            else
            {
                ans[m++] = 'b';
                k -= q[t[pos][0]];
                pos = t[pos][1];
            }
        }
        else
        {
            ans[m++] = 'b';
            pos = t[pos][1];
        }
    }
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