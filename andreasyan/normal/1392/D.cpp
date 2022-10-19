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

int dp[N][2][2][2][3];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'L')
            a[i] = 0;
        else
            a[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int s1 = 0; s1 < 2; ++s1)
        {
            for (int s2 = 0; s2 < 2; ++s2)
            {
                for (int f = 0; f < 2; ++f)
                {
                    for (int q = 1; q <= 2; ++q)
                    {
                        dp[i][s1][s2][f][q] = N;
                    }
                }
            }
        }
    }
    for (int s1 = 0; s1 < 2; ++s1)
    {
        for (int s2 = 0; s2 < 2; ++s2)
        {
            int q;
            if (s1 == s2)
                q = 2;
            else
                q = 1;
            dp[2][s1][s2][s2][q] = (a[1] != s1) + (a[2] != s2);
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for (int s1 = 0; s1 < 2; ++s1)
        {
            for (int s2 = 0; s2 < 2; ++s2)
            {
                for (int f = 0; f < 2; ++f)
                {
                    for (int q = 1; q <= 2; ++q)
                    {
                        for (int z = 0; z < 2; ++z)
                        {
                            int ff = z;
                            int qq;
                            if (f == z)
                                qq = q + 1;
                            else
                                qq = 1;
                            if (qq <= 2)
                                dp[i + 1][s1][s2][ff][qq] = min(dp[i + 1][s1][s2][ff][qq], dp[i][s1][s2][f][q] + (z != a[i + 1]));
                        }
                    }
                }
            }
        }
    }
    int ans = N;
    for (int s1 = 0; s1 < 2; ++s1)
    {
        for (int s2 = 0; s2 < 2; ++s2)
        {
            for (int f = 0; f < 2; ++f)
            {
                for (int q = 1; q <= 2; ++q)
                {
                    if (f != s1)
                        ans = min(ans, dp[n][s1][s2][f][q]);
                    else
                    {
                        if (q == 1 && s1 != s2)
                            ans = min(ans, dp[n][s1][s2][f][q]);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
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