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
const int N = 100005, M = 2200006;

int n, m;
vector<int> g[N];
vector<int> gi[N];
pair<int, int> b[M];

vector<int> ans;

bool ck[M];

int c[N];
int fup[N], tin[N], ti;

vector<int> v;

void ubd(int x)
{
    vector<int> vv;
    while (!v.empty())
    {
        vv.push_back(v.back());
        v.pop_back();
        if (vv.back() == x)
            break;
    }
    set<int> s;
    for (int i = 0; i < vv.size(); ++i)
    {
        s.insert(b[vv[i]].fi);
        s.insert(b[vv[i]].se);
    }
    if (sz(s) == sz(vv))
    {
        for (int i = 0; i < vv.size(); ++i)
            ans.push_back(vv[i]);
    }
}

void dfs(int x, int p)
{
    c[x] = 1;
    fup[x] = tin[x] = ++ti;
    int chld = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        int hi = gi[x][i];
        if (!ck[hi])
        {
            ck[hi] = true;
            v.push_back(hi);
        }
        if (h == p)
            continue;
        if (c[h])
        {
            fup[x] = min(fup[x], tin[h]);
        }
        else
        {
            ++chld;
            dfs(h, x);
            if ((p == -1 && chld > 1) || (p != -1 && fup[h] >= tin[x]))
            {
                if (fup[h] > tin[x])
                    v.pop_back();
                else
                    ubd(gi[x][i]);
            }
            fup[x] = min(fup[x], fup[h]);
        }
    }
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
        b[i] = m_p(x, y);
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs(x, -1);
            ubd(-1);
        }
    }

    sort(all(ans));
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i] + 1);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}