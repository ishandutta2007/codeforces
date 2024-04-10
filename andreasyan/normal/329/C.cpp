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
const int INF = 1000000009;

int n, m;
pair<int, int> b[N];

int m1;
vector<int> a1[N];

bool stg()
{
    for (int i = 1; i <= m; ++i)
    {
        int x = b[i].fi;
        int y = b[i].se;
        for (int j = 0; j < a1[x].size(); ++j)
        {
            if (a1[x][j] == y)
                return false;
        }
    }
    return true;
}

bool rec(int x)
{
    if (x == n + 1)
    {
        if (m1 < m)
            return false;
        return stg();
    }
    if (rec(x + 1))
        return true;
    for (int i = x + 1; i <= n; ++i)
    {
        a1[x].push_back(i);
        a1[i].push_back(x);
        ++m1;
        if (a1[x].size() > 2 || a1[i].size() > 2 || m1 > m || !rec(x + 1))
        {
            a1[x].pop_back();
            a1[i].pop_back();
            --m1;
        }
        else
            return true;
        for (int j = i + 1; j <= n; ++j)
        {
            a1[x].push_back(i);
            a1[i].push_back(x);
            a1[x].push_back(j);
            a1[j].push_back(x);
            m1 += 2;
            if (a1[x].size() > 2 || a1[i].size() > 2 || a1[j].size() > 2 || m1 > m || !rec(x + 1))
            {
                a1[x].pop_back();
                a1[i].pop_back();
                a1[x].pop_back();
                a1[j].pop_back();
                m1 -= 2;
            }
            else
                return true;
        }
    }
    return false;
}

int u[N];
void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &b[i].fi, &b[i].se);
    }
    if (n <= 10)
    {
        if (!rec(1))
        {
            printf("-1\n");
        }
        else
        {
            for (int x = 1; x <= n; ++x)
            {
                for (int i = 0; i < a1[x].size(); ++i)
                {
                    int y = a1[x][i];
                    if (x < y)
                        printf("%d %d\n", x, y);
                }
            }
        }
        return;
    }
    while (1)
    {
        for (int i = 1; i <= n; ++i)
            a1[i].clear();
        for (int i = 1; i <= n; ++i)
            u[i] = i;
        for (int i = n; i >= 1; --i)
            swap(u[i], u[rnd() % i + 1]);
        for (int i = 1; i < n; ++i)
        {
            a1[u[i]].push_back(u[i + 1]);
            a1[u[i + 1]].push_back(u[i]);
        }
        a1[u[n]].push_back(u[1]);
        a1[u[1]].push_back(u[n]);
        if (stg())
        {
            for (int x = 1; x <= n; ++x)
            {
                for (int i = 0; i < a1[x].size(); ++i)
                {
                    int y = a1[x][i];
                    if (x < y)
                    {
                        if (m1 < m)
                        {
                            ++m1;
                            printf("%d %d\n", x, y);
                        }
                    }
                }
            }
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}