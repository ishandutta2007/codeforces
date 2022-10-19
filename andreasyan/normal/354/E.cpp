#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int S = 50;

vector<int> v[S];

vector<int> u;
void rec()
{
    if (u.size() == 6)
    {
        int s = 0;
        for (int i = 0; i < 6; ++i)
        {
            s += u[i];
        }
        v[s] = u;
        return;
    }
    u.push_back(0);
    rec();
    u.pop_back();
    u.push_back(4);
    rec();
    u.pop_back();
    u.push_back(7);
    rec();
    u.pop_back();
}

long long ast[S];
void pre()
{
    rec();
    ast[0] = 1;
    for (int i = 1; i < S; ++i)
        ast[i] = ast[i - 1] * 10;
}

bool dp[S][S];

void solv()
{
    long long n;
    scanf("%I64d", &n);
    u.clear();
    while (n)
    {
        u.push_back(n % 10);
        n /= 10;
    }
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    for (int i = 0; i < u.size(); ++i)
    {
        for (int j = 0; j <= 4; ++j)
        {
            if (!dp[i][j])
                continue;
            for (int s = (u[i] - j + 10) % 10; s < S; s += 10)
            {
                if (v[s].empty())
                    continue;
                dp[i + 1][(j + s) / 10] = true;
            }
        }
    }
    if (!dp[u.size()][0])
    {
        printf("-1\n");
        return;
    }
    long long ans[6] = {};
    int k = 0;
    for (int i = u.size(); i > 0; --i)
    {
        for (int j = 0; j <= 4; ++j)
        {
            if (!dp[i - 1][j])
                continue;
            bool z = false;
            for (int s = (u[i - 1] - j + 10) % 10; s < S; s += 10)
            {
                if (v[s].empty())
                    continue;
                if ((j + s) / 10 == k)
                {
                    for (int k = 0; k < 6; ++k)
                    {
                        ans[k] += v[s][k] * ast[i - 1];
                    }
                    k = j;
                    z = true;
                    break;
                }
            }
            if (z)
                break;
        }
    }
    for (int i = 0; i < 6; ++i)
        printf("%I64d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}