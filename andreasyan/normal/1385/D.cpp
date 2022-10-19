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
const int N = 200005;

int n;
char a[N];

int dp[N * 4][26];
int q[N * 4][26];

void rec(int l, int r, int pos)
{
    if (l == r)
    {
        for (int i = 0; i < 26; ++i)
        {
            dp[pos][i] = 1;
            if (a[l] == i)
                dp[pos][i] = 0;
        }
        for (int i = 0; i < 26; ++i)
        {
            q[pos][i] = 0;
            if (a[l] == i)
                q[pos][i] = 1;
        }
        return;
    }
    int m = (l + r) / 2;
    rec(l, m, pos * 2);
    rec(m + 1, r, pos * 2 + 1);
    for (int i = 0; i < 26; ++i)
    {
        if (i + 1 < 26)
        {
            dp[pos][i] = min(r - m - q[pos * 2][i] + dp[pos * 2 + 1][i + 1],
                             r - m - q[pos * 2 + 1][i] + dp[pos * 2][i + 1]);
            dp[pos][i] = min(dp[pos][i], N);
        }
        else
        {
            dp[pos][i] = N;
        }
        q[pos][i] = q[pos * 2][i] + q[pos * 2 + 1][i];
    }
}

void solv()
{
    scanf("%d", &n);
    scanf(" %s", a);
    for (int i = 0; i < n; ++i)
        a[i] -= 'a';
    rec(0, n - 1, 1);
    printf("%d\n", dp[1][0]);
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
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}