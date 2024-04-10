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
const int N = 2000006;

int m;
pair<int, int> b[N];
vector<int> v;
int n;
map<int, int> mp;
int rmp[N];

vector<int> g[N];

int qk, qg;
bool c[N];
void dfs(int x)
{
    c[x] = true;
    v.push_back(x);
    ++qg;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        ++qk;
        if (!c[h])
            dfs(h);
    }
}

void solv()
{
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &b[i].fi, &b[i].se);
    for (int i = 1; i <= m; ++i)
    {
        v.push_back(b[i].fi);
        v.push_back(b[i].se);
    }
    sort(all(v));
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++n;
            rmp[n] = v[i];
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        b[i].fi = mp[b[i].fi];
        b[i].se = mp[b[i].se];
        g[b[i].fi].push_back(b[i].se);
        g[b[i].se].push_back(b[i].fi);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            v.clear();
            qg = 0;
            qk = 0;
            dfs(i);
            qk /= 2;
            if (qg - 1 == qk)
            {
                int maxu = 0, maxi;
                for (int i = 0; i < v.size(); ++i)
                {
                    if (rmp[v[i]] > maxu)
                    {
                        maxu = rmp[v[i]];
                        maxi = i;
                    }
                }
                for (int i = 0; i < v.size(); ++i)
                {
                    if (i == maxi)
                        continue;
                    ans = max(ans, rmp[v[i]]);
                }
            }
            else if (qg == qk)
            {
                for (int i = 0; i < v.size(); ++i)
                    ans = max(ans, rmp[v[i]]);
            }
            else
            {
                printf("-1\n");
                return;
            }
        }
    }
    printf("%d\n", ans);
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