#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;
struct ban
{
    int a, b;
};
bool sod(const ban& a, const ban& b)
{
    return a.a < b.a;
}
bool sob(const ban& a, const ban& b)
{
    return a.a + a.b > b.a + b.b;
}

int n, r;
vector<ban> b, d;

int dp[N][N];

void solv()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i)
    {
        ban t;
        scanf("%d%d", &t.a, &t.b);
        t.a = max(t.a, -t.b);
        if (t.b >= 0)
            d.push_back(t);
        else
            b.push_back(t);
    }
    sort(d.begin(), d.end(), sod);
    int pans = 0;
    for (int i = 0; i < d.size(); ++i)
    {
        if (r >= d[i].a)
        {
            ++pans;
            r += d[i].b;
        }
    }
    sort(b.begin(), b.end(), sob);
    for (int i = 0; i <= b.size(); ++i)
    {
        for (int j = 0; j <= b.size(); ++j)
            dp[i][j] = -1;
    }
    dp[0][0] = r;
    for (int i = 0; i < b.size(); ++i)
    {
        for (int j = 0; j <= b.size(); ++j)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (dp[i][j] >= b[i].a)
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + b[i].b);
        }
    }
    for (int j = b.size(); j >= 0; --j)
    {
        if (dp[b.size()][j] >= 0)
        {
            printf("%d\n", pans + j);
            return;
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