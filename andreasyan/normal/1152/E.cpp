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
int b1[N], b2[N];

vector<int> v;

vector<int> g[N];
vector<int> gi[N];

vector<int> ans;

bool c[N];

void dfs(int x)
{
    while (1)
    {
        if (g[x].empty())
            break;
        int h = g[x].back();
        int hi = gi[x].back();
        g[x].pop_back();
        gi[x].pop_back();
        if (c[hi])
            continue;
        c[hi] = true;
        dfs(h);
    }
    ans.push_back(v[x]);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
        scanf("%d", &b1[i]);
    for (int i = 1; i < n; ++i)
        scanf("%d", &b2[i]);
    for (int i = 1; i < n; ++i)
    {
        if (b1[i] > b2[i])
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        v.push_back(b1[i]);
        v.push_back(b2[i]);
    }
    sort(all(v));
    for (int i = 1; i < n; ++i)
    {
        b1[i] = lower_bound(all(v), b1[i]) - v.begin();
        b2[i] = lower_bound(all(v), b2[i]) - v.begin();
        int x = b1[i], y = b2[i];
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }
    int q = 0;
    for (int i = 0; i < n * 2; ++i)
    {
        q += (g[i].size() % 2);
    }
    if (q != 2 && q != 0)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n * 2; ++i)
    {
        if (g[i].size() % 2 == 1)
        {
            dfs(i);
            break;
        }
    }
    if (ans.empty())
    {
        for (int i = 0; i < n * 2; ++i)
        {
            if (!g[i].empty())
            {
                dfs(i);
                break;
            }
        }
    }
    if (ans.size() != n)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
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