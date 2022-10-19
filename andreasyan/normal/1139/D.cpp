#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, M = 1000000007;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int r[N];
void pre()
{
    for (int i = 0; i < N; ++i)
        r[i] = ast(i, M - 2);
}

int n;
int dp[N];
double dpp[N];

vector<int> v[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
            v[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            dp[i] = 0;
            dpp[i] = 0;
            continue;
        }
        vector<int> q(v[i].size());
        for (int j = v[i].size() - 1; j >= 0; --j)
        {
            q[j] = (n / v[i][j]);
            for (int k = j + 1; k < v[i].size(); ++k)
            {
                if (v[i][k] % v[i][j] == 0)
                    q[j] -= q[k];
            }
        }
        /*vector<int> hastatq;
        hastatq.assign(v[i].size(), 0);
        for (int u = 1; u <= n; ++u)
        {
            int j = lower_bound(v[i].begin(), v[i].end(), gcd(u, i)) - v[i].begin();
            hastatq[j]++;
        }
        for (int j = 0; j < v[i].size(); ++j)
            assert(hastatq[j] == q[j]);*/
        /*for (int j = 0; j < v[i].size() - 1; ++j)
        {
            dp[i] = (((dp[v[i][j]] * 1LL * (q[j] + 1)) % M) * 1LL * r[n - q.back()]) % M;
            dpp[i] = (dpp[v[i][j]] * (q[j] + 1) / (double)(n - q.back()));
        }*/
        for (int j = 0; j < v[i].size() - 1; ++j)
        {
            dp[i] = (dp[i] + (((dp[v[i][j]] * 1LL * q[j]) % M) * 1LL * r[n - q.back()]) % M) % M;
            dpp[i] = (dpp[v[i][j]] * q[j] / (double)(n - q.back()));
        }
        dp[i] = (dp[i] + (n * 1LL * r[(n - q.back())]) % M) % M;
        dpp[i] = (dpp[i] + n / (double)(n - q.back()));
    }
    int ans = 0;
    double anss = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + ((dp[i] + 1) * 1LL * r[n]) % M) % M;
        anss = (anss + (dpp[i] + 1) / n);
    }
    printf("%d\n", ans);
    //printf("%.12f\n", anss);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}