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
const int N = 1100006;
const pair<int, int> M = m_p(993019889, 997084241);
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

int n;
char a[N];

pair<int, int> p[N];

int m;
char b[13];

int mm[N / 10];
int ans[N / 10][13];

int z;
int t[N][26];
vector<int> v[N];

void solv()
{
    n = 1000000;
    for (int i = 1; i <= n; ++i)
        a[i] = 'a' + rnf() % 2;

    cin >> (a + 1);
    for (n = 1; a[n]; ++n){}
    --n;

    for (int i = 1; i <= n; ++i)
        p[i] = sum(p[i - 1], pro(ast[i], m_p(a[i], a[i])));

    int qq = 100000;
    cin >> qq;
    z = 0;
    for (int ii = 1; ii <= qq; ++ii)
    {
        m = 10;
        for (int i = 1; i <= m; ++i)
            b[i] = 'a' + rnf() % 2;

        cin >> (b + 1);
        for (m = 1; b[m]; ++m){}
        --m;
        mm[ii] = m;

        for (int i = n + 1; i <= n + m; ++i)
            p[i] = sum(p[i - 1], pro(ast[i], m_p(b[i - n], b[i - n])));

        for (int i = 1; i <= m; ++i)
            ans[ii][i] = 0;
        for (int i = n + 1; i <= n + m; ++i)
        {
            bool z = false;
            for (int d = i - 1; d > n; --d)
            {
                if (dif(p[i], p[i - d]) == pro(p[d], ast[i - d]))
                {
                    ans[ii][i - n] = d;
                    z = true;
                    break;
                }
            }
            if (z)
                continue;

            for (int d = i - n; d >= 1; --d)
            {
                if (dif(p[i], p[i - d]) == pro(p[d], ast[i - d]))
                {
                    ans[ii][i - n] = d;
                    break;
                }
            }
        }

        int pos = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (!t[pos][b[i] - 'a'])
            {
                t[pos][b[i] - 'a'] = ++z;
            }
            pos = t[pos][b[i] - 'a'];
            v[pos].push_back(ii);
        }

        /*for (int i = 1; i <= m; ++i)
            cout << ans[ii][i] << ' ';
        cout << "\n";*/
    }

    for (int i = n; i >= 1; --i)
    {
        if (!(pro(p[i - 1], ast[n - (i - 1)]) == dif(p[n], p[n - (i - 1)])))
            continue;
        int pos = 0;
        for (int j = i; j <= n; ++j)
        {
            if (!t[pos][a[j] - 'a'])
                break;
            pos = t[pos][a[j] - 'a'];
            while (!v[pos].empty())
            {
                ans[v[pos].back()][j - i + 1] = max(ans[v[pos].back()][j - i + 1], j);
                v[pos].pop_back();
            }
        }
    }

    for (int ii = 1; ii <= qq; ++ii)
    {
        for (int i = 1; i <= mm[ii]; ++i)
            cout << ans[ii][i] << ' ';
        cout << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}