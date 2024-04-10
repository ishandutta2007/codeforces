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
const int N = 253;

const pair<int, int> M = m_p(934823599, 931299157);
const int P = 307;

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

pair<int, int> ast[N];
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}

int n, m;
char a[N][N];

pair<int, int> u[N];

ll ans;
int d[N];
void solvv()
{
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i)
    {
        d[i] = 1;
        if (i <= r)
            d[i] = min(r - i + 1, d[l + r - i]);
        while (i - d[i] >= 1 && i + d[i] <= n && u[i - d[i]] == u[i + d[i]])
            ++d[i];
        if (i + d[i] - 1 > r)
        {
            r = i + d[i] - 1;
            l = i - d[i] + 1;
        }
        if (u[i].fi >= 0)
            ans += d[i];
    }

    l = 0, r = 0;
    for (int i = 1; i <= n; ++i)
    {
        d[i] = 0;
        if (i <= r)
            d[i] = min(r - i + 1, d[l + r - i + 1]);
        while (i - d[i] - 1 >= 1 && i + d[i] <= n && u[i - d[i] - 1] == u[i + d[i]])
            ++d[i];
        if (i + d[i] - 1 > r)
        {
            r = i + d[i] - 1;
            l = i - d[i];
        }
        ans += d[i];
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));

    for (int l = 1; l <= m; ++l)
    {
        int q[N][26] = {};
        pair<int, int> h[N] = {};
        int k[N] = {};
        for (int r = l; r <= m; ++r)
        {
            for (int i = 1; i <= n; ++i)
            {
                int j = a[i][r] - 'a';

                if (q[i][j] % 2 == 1)
                    --k[i];
                h[i] = dif(h[i], pro(m_p(q[i][j] + 1, q[i][j] + 1), ast[j]));

                ++q[i][j];

                h[i] = sum(h[i], pro(m_p(q[i][j] + 1, q[i][j] + 1), ast[j]));
                if (q[i][j] % 2 == 1)
                    ++k[i];

                if (k[i] <= 1)
                    u[i] = h[i];
                else
                    u[i] = m_p(-i, -i);
            }
            solvv();
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    /*int x = 900000000 + rnd() % 50000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);
    x = 900000000 + rnd() % 50000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);*/
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}