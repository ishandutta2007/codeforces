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
const int N = 300005;
const pair<int, int> M = m_p(781908917, 956603663);
const int P = 307;

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}

pair<int, int> ast[N];
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int n;
char a[N];

pair<int, int> p[N];

vector<int> v;

unordered_set<ll> s;

void solv()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        scanf(" %s", a);
        n = strlen(a);
        if (ty == 1)
        {
            bool z = false;
            for (int i = 0; i < v.size(); ++i)
            {
                if (v[i] == n)
                {
                    z = true;
                    break;
                }
            }
            if (!z)
                v.push_back(n);
            pair<int, int> h = m_p(0, 0);
            for (int i = 0; i < n; ++i)
                h = sum(h, pro(ast[i], m_p(a[i], a[i])));
            h = pro(h, ast[N - n]);
            s.insert(h.fi * 1LL * h.se);
        }
        else if (ty == 2)
        {
            pair<int, int> h = m_p(0, 0);
            for (int i = 0; i < n; ++i)
                h = sum(h, pro(ast[i], m_p(a[i], a[i])));
            h = pro(h, ast[N - n]);
            s.erase(h.fi * 1LL * h.se);
        }
        else
        {
            p[0] = m_p(a[0], a[0]);
            for (int i = 1; i < n; ++i)
                p[i] = sum(p[i - 1], pro(ast[i], m_p(a[i], a[i])));
            int ans = 0;
            for (int l = 0; l < n; ++l)
            {
                for (int i = 0; i < v.size(); ++i)
                {
                    int r = l + v[i] - 1;
                    if (l >= n)
                        continue;
                    pair<int, int> h = p[r];
                    if (l)
                        h = dif(h, p[l - 1]);
                    h = pro(h, ast[N - (r + 1)]);
                    if (s.find(h.fi * 1LL * h.se) != s.end())
                        ++ans;
                }
            }
            printf("%d\n", ans);
            fflush(stdout);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}