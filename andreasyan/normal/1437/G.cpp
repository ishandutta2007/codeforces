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
const pair<int, int> M = m_p(998783749, 998198599);
const int P = 307;
const int S = 550;

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

int n, qq;

int bn[N];
char b[N];

int x[N];

pair<int, int> h[N];
vector<int> big;

int z;
int t[N][26];
int maxu[N];
multiset<int> s[N];

int poss[N];

pair<int, int> p[N];

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 0; i < N; ++i)
        maxu[i] = -1;
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", b);
        bn[i] = strlen(b);

        if (bn[i] > S)
        {
            big.push_back(i);
            for (int j = 0; j < bn[i]; ++j)
                h[i] = sum(h[i], pro(ast[j], m_p(b[j], b[j])));
        }
        else
        {
            int pos = 0;
            for (int j = 0; j < bn[i]; ++j)
            {
                if (!t[pos][b[j] - 'a'])
                    t[pos][b[j] - 'a'] = ++z;
                pos = t[pos][b[j] - 'a'];
            }
            poss[i] = pos;
            s[pos].insert(0);
            maxu[pos] = 0;
        }
    }

    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int i, x0;
            scanf("%d%d", &i, &x0);
            if (bn[i] > S)
            {
                x[i] = x0;
            }
            else
            {
                s[poss[i]].erase(s[poss[i]].find(x[i]));
                x[i] = x0;
                s[poss[i]].insert(x0);
                maxu[poss[i]] = *(--s[poss[i]].end());
            }
        }
        else
        {
            int ans = -1;

            scanf(" %s", b);
            bn[0] = strlen(b);

            p[0] = m_p(b[0], b[0]);
            for (int i = 1; i < bn[0]; ++i)
                p[i] = sum(p[i - 1], pro(ast[i], m_p(b[i], b[i])));

            for (int i = 0; i < bn[0]; ++i)
            {
                int pos = 0;
                for (int j = i; j < min(bn[0], i + S); ++j)
                {
                    if (!t[pos][b[j] - 'a'])
                        break;
                    pos = t[pos][b[j] - 'a'];
                    ans = max(ans, maxu[pos]);
                }
                for (int j = 0; j < big.size(); ++j)
                {
                    int k = big[j];

                    if (i + bn[k] - 1 < bn[0])
                    {
                        pair<int, int> pp = m_p(0, 0);
                        if (i)
                            pp = p[i - 1];
                        if (pro(h[k], ast[i]) == dif(p[i + bn[k] - 1], pp))
                            ans = max(ans, x[k]);
                    }
                }
            }
            printf("%d\n", ans);
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
    /*int x = 990000000 + rnd() % 10000000;
    while (!prime(x))
        ++x;
    printf("%d\n", x);*/
    pre();
    solv();
    return 0;
}