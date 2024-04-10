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

int n;
vector<int> a[N];

bool c[N];
int q[N];

void dfs(int x)
{
    if (a[x].size() >= 3)
    {
        ++q[x];
        return;
    }
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (a[x].size() == 1 && !c[x])
            dfs(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            continue;
        int qq = 0;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (c[h])
                continue;
            if (sz(a[h]) - min(2, q[h]) > 1)
                ++qq;
        }
        if (qq > 2)
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
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