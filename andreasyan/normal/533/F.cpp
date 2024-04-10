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
const pair<int, int> M = m_p(781993543, 529785001);
const int P = 300317;

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

bool isprime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

pair<int, int> ast[N];

void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}

int n, m;
char a[N], b[N];

pair<int, int> p[26][N];

int sb[26];
pair<int, int> hb[26];

void solv()
{
    scanf("%d%d", &n, &m);
    scanf(" %s %s", (a + 1), (b + 1));
    for (int k = 0; k < 26; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            p[k][i] = p[k][i - 1];
            if (a[i] == 'a' + k)
            {
                p[k][i] = sum(p[k][i], ast[i]);
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (sb[b[i] - 'a'] == 0)
            sb[b[i] - 'a'] = i;
        hb[b[i] - 'a'] = sum(hb[b[i] - 'a'], ast[i]);
    }
    vector<int> ans;
    for (int l = 1; l <= n - m + 1; ++l)
    {
        int r = l + m - 1;
        bool z = true;
        int u[26];
        for (int k = 0; k < 26; ++k)
            u[k] = -1;
        for (int k = 0; k < 26; ++k)
        {
            if (!sb[k])
                continue;
            int ka = a[l + sb[k] - 1] - 'a';
            pair<int, int> ha = dif(p[ka][r], p[ka][l - 1]);
            if (pro(hb[k], ast[l - 1]) != ha)
            {
                z = false;
                break;
            }
            if (ka != k)
            {
                if (u[k] != -1 && u[k] != ka)
                {
                    z = false;
                    break;
                }
                if (u[ka] != -1 && u[ka] != k)
                {
                    z = false;
                    break;
                }
                u[k] = ka;
                u[ka] = k;
            }
        }
        if (z)
            ans.push_back(l);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}