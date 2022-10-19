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
const int N = 100005;

int n, m, k;
vector<int> g[N];

int q[N];

set<pair<int, int> > s;

void solv()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        q[x] = 0;
    }
    s.clear();

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int x = 1; x <= n; ++x)
        sort(all(g[x]));

    for (int x = 1; x <= n; ++x)
    {
        q[x] = sz(g[x]);
        s.insert(m_p(q[x], x));
    }

    while (!s.empty())
    {
        int x = s.begin()->se;
        if (q[x] >= k)
        {
            printf("1 %d\n", sz(s));
            for (auto it = s.begin(); it != s.end(); ++it)
                printf("%d ", it->se);
            printf("\n");
            return;
        }
        s.erase(m_p(q[x], x));
        q[x] = -1;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (s.find(m_p(q[h], h)) == s.end())
                continue;
            s.erase(m_p(q[h], h));
            --q[h];
            s.insert(m_p(q[h], h));
        }
    }

    //////////////////////////////////////////////////////

    if (k > 500)
    {
        printf("-1\n");
        return;
    }

    for (int x = 1; x <= n; ++x)
    {
        q[x] = sz(g[x]);
        s.insert(m_p(q[x], x));
    }

    while (!s.empty())
    {
        int x = s.begin()->se;
        if (q[x] >= k - 1)
        {
            vector<int> v;
            v.push_back(x);
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (s.find(m_p(q[h], h)) == s.end())
                    continue;
                v.push_back(h);
            }
            bool z = true;
            for (int i = 0; i < sz(v); ++i)
            {
                int h = v[i];
                for (int j = 0; j < sz(v); ++j)
                {
                    int hh = v[j];
                    if (h == hh)
                        continue;
                    if (!binary_search(all(g[h]), hh))
                    {
                        z = false;
                        break;
                    }
                }
                if (!z)
                    break;
            }
            if (z)
            {
                printf("2\n");
                for (int i = 0; i < k; ++i)
                {
                    printf("%d ", v[i]);
                }
                printf("\n");
                return;
            }
        }
        s.erase(m_p(q[x], x));
        q[x] = -1;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (s.find(m_p(q[h], h)) == s.end())
                continue;
            s.erase(m_p(q[h], h));
            --q[h];
            s.insert(m_p(q[h], h));
        }
    }
    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}