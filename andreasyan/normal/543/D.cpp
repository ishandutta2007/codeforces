#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n;
int p[N];
vector<int> a[N];

int d[N];
void dfs0(int x)
{
    d[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs0(h);
        d[x] = (d[x] * 1LL * (d[h] + 1)) % M;
    }
}

int ans[N];

void dfs(int x, int dp)
{
    ans[x] = (d[x] * 1LL * (dp + 1)) % M;
    vector<int> p(a[x].size()), s(a[x].size());
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (i == 0)
            p[i] = (d[h] + 1);
        else
            p[i] = (p[i - 1] * 1LL * (d[h] + 1)) % M;
    }
    for (int i = (int)a[x].size() - 1; i >= 0; --i)
    {
        int h = a[x][i];
        if (i == a[x].size() - 1)
            s[i] = (d[h] + 1);
        else
            s[i] = (s[i + 1] * 1LL * (d[h] + 1)) % M;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        int u = (dp + 1) % M;
        if (i)
            u = (u * 1LL * p[i - 1]) % M;
        if (i < a[x].size() - 1)
            u = (u * 1LL * s[i + 1]) % M;
        dfs(h, u);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int x = 2; x <= n; ++x)
    {
        scanf("%d", &p[x]);
        a[p[x]].push_back(x);
    }
    dfs0(1);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
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