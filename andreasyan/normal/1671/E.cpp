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
const int N = 300005, M0 = 998244353;
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

int ans;
pair<int, int> h[N];

void dfs(int x, int q)
{
    if (q == 1)
    {
        h[x] = m_p(a[x], a[x]);
        return;
    }

    dfs(x * 2, q / 2);
    dfs(x * 2 + 1, q / 2);

    if (h[x * 2] != h[x * 2 + 1])
        ans = (ans * 2) % M0;

    h[x] = sum(min(h[x * 2], h[x * 2 + 1]), pro(ast[q / 2], max(h[x * 2], h[x * 2 + 1])));
    h[x] = sum(m_p(a[x], a[x]), pro(ast[1], h[x]));
}

void solv()
{
    cin >> n;
    cin >> (a + 1);

    ans = 1;
    dfs(1, (1 << n) - 1);

    cout << ans << "\n";
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