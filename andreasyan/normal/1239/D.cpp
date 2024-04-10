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
const int N = 1000006;

int n, m;
vector<int> a[N], b[N];

int c[N];

vector<int> v;
void dfs1(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs1(h);
    }
    v.push_back(x);
}

int k;
void dfs2(int x)
{
    c[x] = k;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int h = b[x][i];
        if (!c[h])
            dfs2(h);
    }
}

bool cc[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        b[i].clear();
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        b[y].push_back(x);
    }
    v.clear();
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs1(x);
        }
    }
    reverse(all(v));
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    k = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs2(x);
        }
    }
    if (k == 1)
    {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    for (int i = 1; i <= k; ++i)
        cc[i] = false;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (c[x] != c[y])
                cc[c[x]] = true;
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        if (!cc[i])
        {
            vector<int> ans1, ans2;
            for (int x = 1; x <= n; ++x)
            {
                if (c[x] == i)
                    ans1.push_back(x);
                else
                    ans2.push_back(x);
            }
            printf("%d %d\n", ans1.size(), ans2.size());
            for (int i = 0; i < ans1.size(); ++i)
                printf("%d ", ans1[i]);
            printf("\n");
            for (int i = 0; i < ans2.size(); ++i)
                printf("%d ", ans2[i]);
            printf("\n");
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}