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
const int N = 3003;

int n, m;
vector<int> g[N];
vector<int> gi[N];

bool c[N];
bool ck[N];

void dfs0(int x)
{
    if (c[x])
        return;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        int hi = gi[x][i];
        if (ck[hi])
            continue;
        dfs0(h);
    }
}

vector<int> ans;
void dfs(int x)
{
    while (!g[x].empty())
    {
        int h = g[x].back();
        int hi = gi[x].back();
        g[x].pop_back();
        gi[x].pop_back();
        if (ck[hi])
            continue;
        ck[hi] = true;
        dfs(h);
    }
    ans.push_back(x);
}

void finish_him(int x)
{
    vector<int> v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (ck[gi[x][i]])
            v.push_back(h);
    }
    dfs(x);
    ans.push_back(-1);
    for (int i = 0; i < v.size(); ++i)
    {
        ans.push_back(v[i]);
        ans.push_back(x);
    }

    for (int i = 0; i < m; ++i)
        assert(ck[i]);

    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    for (int x = 1; x <= n; ++x)
    {
        int q = 0;
        memset(c, false, sizeof c);
        memset(ck, false, sizeof ck);

        c[x] = true;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            c[h] = true;
        }
        for (int x = 1; x <= n; ++x)
        {
            if (c[x])
                continue;
            q += (sz(g[x]) % 2);
        }

        if (q > 1)
            continue;
        if (q == 1)
        {
            int q0 = 0;
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (sz(g[h]) % 2 == 1)
                    ck[gi[x][i]] = true;
                else
                    ++q0;
            }
            if (q0 % 2 == 0)
                continue;
            memset(c, false, sizeof c);
            dfs0(x);
            bool z = true;
            for (int x = 1; x <= n; ++x)
            {
                if (g[x].empty() || (sz(g[x]) == 1 && ck[gi[x][0]]))
                    continue;
                if (!c[x])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                finish_him(x);
                return;
            }
        }
        else
        {
            int q0 = 0;
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (sz(g[h]) % 2 == 1)
                    ck[gi[x][i]] = true;
                else
                    ++q0;
            }
            if (q0 % 2 == 0)
            {
                memset(c, false, sizeof c);
                dfs0(x);
                bool z = true;
                for (int x = 1; x <= n; ++x)
                {
                    if (g[x].empty() || (sz(g[x]) == 1 && ck[gi[x][0]]))
                        continue;
                    if (!c[x])
                    {
                        z = false;
                        break;
                    }
                }
                if (z)
                {
                    finish_him(x);
                    return;
                }

                for (int i = 0; i < g[x].size(); ++i)
                {
                    int h = g[x][i];
                    ck[gi[x][i]] ^= true;

                    memset(c, false, sizeof c);
                    dfs0(x);
                    bool z = true;
                    for (int x = 1; x <= n; ++x)
                    {
                        if (g[x].empty() || (sz(g[x]) == 1 && ck[gi[x][0]]))
                            continue;
                        if (!c[x])
                        {
                            z = false;
                            break;
                        }
                    }
                    if (z)
                    {
                        finish_him(x);
                        return;
                    }

                    ck[gi[x][i]] ^= true;
                }
            }
        }
    }

    printf("0\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}