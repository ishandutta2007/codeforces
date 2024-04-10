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

int n;
int s[N];
int m;
vector<int> g[N];
vector<pair<int, bool> > gi[N];

int ans[N];

bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        dfs(h);
        if (gi[x][i].se == true)
        {
            ans[gi[x][i].fi] = s[h];
            s[x] += s[h];
            s[h] = 0;
        }
        else
        {
            ans[gi[x][i].fi] = -s[h];
            s[x] += s[h];
            s[h] = 0;
        }
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &s[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(m_p(i, true));
        gi[y].push_back(m_p(i, false));
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += s[i];
    }
    if (sum)
    {
        printf("Impossible\n");
        return;
    }
    dfs(1);
    printf("Possible\n");
    for (int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);
    printf("\n");
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