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
const int N = 103;

bool dp[N][N];

bool stg(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return false;
    if (!stg(b % a, a))
        return true;
    if (a % 2 == 1)
    {
        return ((b / a) % 2 == 0);
    }
    return (((b / a) % (a + 1)) % 2 == 0);
}

void solv()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        if (stg(a, b))
            printf("First\n");
        else
            printf("Second\n");
    }
    return;
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < N; ++j)
        {
            if (i > j)
            {
                if (!dp[i % j][j])
                {
                    dp[i][j] = true;
                    continue;
                }
                for (int x = j; x <= i; x *= j)
                {
                    if (!dp[i - x][j])
                    {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
            else
            {
                if (!dp[i][j % i])
                {
                    dp[i][j] = true;
                    continue;
                }
                for (int x = i; x <= j; x *= i)
                {
                    if (!dp[i][j - x])
                    {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%d", dp[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (stg(i, j) != dp[i][j])
            {
                printf("WA\n");
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}