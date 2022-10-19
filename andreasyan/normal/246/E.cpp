#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const pair<int, int> M = m_p(771921809, 648034241);
const int P = 349;

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.first + b.first) % M.first, (a.second + b.second) % M.second);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.first * 1LL * b.first) % M.first, (a.second * 1LL * b.second) % M.second);
}

pair<int, int> ast[N];

void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
    {
        ast[i] = pro(ast[i - 1], m_p(P, P));
    }
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

int n;
int p[N];
pair<int, int> h[N];
vector<int> a[N];

vector<pair<int, int> > v[N];

int ans[N];

map<int, int> yans[N];
set<pair<int, pair<int, int> > > s[N];

void dfs(int x, int d)
{
    yans[x][d]++;
    s[x].insert(m_p(d, h[x]));
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h, d + 1);
        if (s[h].size() > s[x].size())
        {
            swap(s[h], s[x]);
            swap(yans[h], yans[x]);
        }
        for (set<pair<int, pair<int, int> > >::iterator it = s[h].begin(); it != s[h].end(); ++it)
        {
            if (s[x].find(*it) != s[x].end())
                continue;
            s[x].insert(*it);
            yans[x][it->first]++;
        }
    }
    for (int i = 0; i < v[x].size(); ++i)
    {
        if (yans[x].find(d + v[x][i].first) == yans[x].end())
            continue;
        ans[v[x][i].second] = yans[x][d + v[x][i].first];
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        char name[25];
        scanf(" %s%d", name, &p[i]);
        a[p[i]].push_back(i);
        int m = strlen(name);
        for (int j = 0; j < m; ++j)
        {
            h[i] = sum(h[i], pro(ast[j], m_p(name[j], name[j])));
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        int x, k;
        scanf("%d%d", &x, &k);
        v[x].push_back(m_p(k, i));
    }
    dfs(0, 0);
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
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