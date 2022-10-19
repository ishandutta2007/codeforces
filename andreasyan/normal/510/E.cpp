#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 202;

bool prime[N * N];
void pre()
{
    prime[0] = prime[1] = true;
    for (int i = 2; i < N * N; ++i)
    {
        if (prime[i])
            continue;
        for (int j = i * i; j < N * N; j += i)
            prime[j] = true;
    }
}

int n;
int a[N];

int g[N][N];

bool c[N];
int p[N];
void bfs()
{
    memset(c, false, sizeof c);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == n + 1)
            return;
        for (int h = 0; h <= n + 1; ++h)
        {
            if (!g[x][h])
                continue;
            if (!c[h])
            {
                c[h] = true;
                p[h] = x;
                q.push(h);
            }
        }
    }
}

vector<int> v;
void dfs(int x)
{
    c[x] = true;
    v.push_back(x);
    if (a[x] % 2 == 0)
    {
        int q = 0;
        for (int h = 1; h <= n; ++h)
        {
            if (prime[a[x] + a[h]])
                continue;
            if (g[x][h] == 1)
                continue;
            ++q;
            if (c[h])
                continue;
            dfs(h);
        }
        assert(q == 2);
    }
    else
    {
        int q = 0;
        for (int h = 1; h <= n; ++h)
        {
            if (prime[a[x] + a[h]])
                continue;
            if (g[x][h] == 0)
                continue;
            ++q;
            if (c[h])
                continue;
            dfs(h);
        }
        assert(q == 2);
    }
}

void solv()
{
    scanf("%d", &n);
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if ((a[i] % 2) == 1)
            ++q;
    }
    if (n % 2 != 0 || q != n / 2)
    {
        printf("Impossible\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
            g[0][i] = 2;
        else
            g[i][n + 1] = 2;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 1)
            continue;
        for (int j = 1; j <= n; ++j)
        {
            if (a[j] % 2 == 0)
                continue;
            if (!prime[a[i] + a[j]])
                g[i][j] = 1;
        }
    }
    while (1)
    {
        bfs();
        if (!c[n + 1])
            break;
        int minu = g[p[n + 1]][n + 1];
        for (int x = n + 1; x; x = p[x])
        {
            minu = min(minu, g[p[x]][x]);
        }
        for (int x = n + 1; x; x = p[x])
        {
            g[p[x]][x] -= minu;
            g[x][p[x]] += minu;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
            continue;
        if (g[n + 1][i] != 2)
        {
            printf("Impossible\n");
            return;
        }
    }
    memset(c, false, sizeof c);
    vector<vector<int> > ans;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            v.clear();
            dfs(i);
            ans.push_back(v);
            for (int i = 0; i < v.size() - 1; ++i)
            {
                if (prime[a[v[i]] + a[v[i + 1]]])
                    assert(false);
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); ++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}