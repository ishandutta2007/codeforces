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

int n, k;
vector<int> a[N];
bool c[N];

int q[N];
void dfs0(int x, int p)
{
    if (c[x])
        q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (q[h] > k)
            return dfsc(h, x);
    }
    return x;
}

vector<int> v;
void dfs(int x, int p)
{
    if (c[x])
        v.push_back(x);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < (n - 1); ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 0; i < 2 * k; ++i)
    {
        int x;
        scanf("%d", &x);
        c[x] = true;
    }
    dfs0(1, 1);
    int u = dfsc(1, 1);
    printf("1\n%d\n", u);
    dfs(u, u);
    for (int i = 0; i < k; ++i)
    {
        printf("%d %d %d\n", v[i], v[i + k], u);
    }
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