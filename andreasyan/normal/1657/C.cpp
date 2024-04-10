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
const int N = 500005;
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

pair<int, int> p[N], s[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    p[0] = m_p(0, 0);
    for (int i = 1; i <= n; ++i)
        p[i] = sum(p[i - 1], pro(m_p(a[i], a[i]), ast[i]));
    s[n + 1] = m_p(0, 0);
    for (int i = n; i >= 1; --i)
        s[i] = sum(s[i + 1], pro(m_p(a[i], a[i]), ast[n - i + 1]));

    int q = 0;
    int u = 1;
    while (u <= n)
    {
        int x = 0;
        bool z = false;
        for (int i = u; i <= n; ++i)
        {
            if (x >= 0)
            {
                if (a[i] == '(')
                    ++x;
                else
                    --x;
            }
            if (x == 0)
            {
                ++q;
                u = i + 1;
                z = true;
                break;
            }
            if (i > u && pro(dif(p[i], p[u - 1]), ast[n - i]) == pro(dif(s[u], s[i + 1]), ast[u - 1]))
            {
                ++q;
                u = i + 1;
                z = true;
                break;
            }
        }
        if (!z)
            break;
    }

    cout << q << ' ' << n - u + 1 << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}