#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int xxx, yyy;
int gcd(int a, int b, int& x = xxx, int& y = yyy)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1_;
    int g = gcd(b % a, a, x1, y1_);
    x = y1_ - (b / a) * x1;
    y = x1;
    return g;
}

int n, m;

vector<int> v[N];

int dp[N];
int dpp[N];

void solv()
{
    scanf("%d%d", &n, &m);
    set<int> s;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        if (x == 0)
            x = m;
        s.insert(x);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (s.find(i) != s.end())
            continue;
        v[gcd(i, m)].push_back(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (v[i].size() > dp[i])
        {
            dp[i] = v[i].size();
            dpp[i] = 0;
        }
        for (int j = i + i; j <= m; j += i)
        {
            if (dp[i] + (int)v[j].size() > dp[j])
            {
                dp[j] = dp[i] + (int)v[j].size();
                dpp[j] = i;
            }
        }
    }
    int maxu = 0;
    for (int i = 1; i <= m; ++i)
    {
        maxu = max(maxu, dp[i]);
    }
    vector<int> p;
    for (int i = 1; i <= m; ++i)
    {
        if (maxu == dp[i])
        {
            while (1)
            {
                for (int j = 0; j < v[i].size(); ++j)
                    p.push_back(v[i][j]);
                if (dpp[i] == 0)
                    break;
                i = dpp[i];
            }
            reverse(p.begin(), p.end());
            break;
        }
    }
    printf("%d\n", p.size());
    vector<int> a(p.size());
    a[0] = (p[0] % m);
    for (int i = 1; i < p.size(); ++i)
    {
        int g = gcd(p[i - 1], m);
        gcd(p[i - 1] / g, m / g, a[i]);
        a[i] = ((a[i] % (m / g)) + (m / g)) % (m / g);
        a[i] = (a[i] * 1LL * (p[i] / g)) % (m / g);
    }
    for (int i = 0; i < p.size(); ++i)
        printf("%d ", a[i]);
    printf("\n");
    return;
    for (int i = 0; i < p.size(); ++i)
        printf("%d ", p[i]);
    printf("\n");
    p[0] = a[0];
    for (int i = 1; i < p.size(); ++i)
        p[i] = (p[i - 1] * 1LL * a[i]) % m;
    for (int i = 0; i < p.size(); ++i)
        printf("%d ", p[i]);
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