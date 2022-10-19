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
const int N = 500005;

int n, m;
vector<int> g[N];
char s[N];

int tin[N], tout[N], ti;
int rtin[N];
int d[N];

vector<int> v[N];

void dfs(int x, int p)
{
    tin[x] = ++ti;
    rtin[tin[x]] = x;
    d[x] = d[p] + 1;
    v[d[x]].push_back(tin[x]);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h, x);
    }
    tout[x] = ti;
}

int p[N][26];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i)
    {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }
    scanf(" %s", (s + 1));
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = rtin[v[i][j]];
            if (j)
            {
                for (int k = 0; k < 26; ++k)
                    p[x][k] = p[rtin[v[i][j - 1]]][k];
            }
            p[x][s[x] - 'a']++;
        }
    }
    while (m--)
    {
        int x, d;
        scanf("%d%d", &x, &d);
        int li = lower_bound(all(v[d]), tin[x]) - v[d].begin() - 1;
        int ri = upper_bound(all(v[d]), tout[x]) - v[d].begin() - 1;
        if (li < ri)
        {
            int q = 0;
            for (int k = 0; k < 26; ++k)
            {
                if (li >= 0)
                {
                    if ((p[rtin[v[d][ri]]][k] - p[rtin[v[d][li]]][k]) % 2 == 1)
                        ++q;
                }
                else
                {
                    if ((p[rtin[v[d][ri]]][k]) % 2 == 1)
                        ++q;
                }
            }
            if (q <= 1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("Yes\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}