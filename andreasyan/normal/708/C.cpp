#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 400005;

int n;
vector<int> a[N];

int s[N], dp[N];

void dfs0(int x, int p)
{
    s[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        s[x] += s[h];
        dp[x] = max(dp[x], dp[h]);
    }
    if (s[x] <= n / 2)
        dp[x] = s[x];
}

bool ans[N];

void dfs1(int x, int p, int dpp)
{
    int sp = n - s[x];
    ans[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            if (sp > n / 2)
            {
                if (sp - dpp <= n / 2)
                {
                    ans[x] = true;
                }
                else
                {
                    ans[x] = false;
                }
                break;
            }
            continue;
        }
        if (s[h] > n / 2)
        {
            if (s[h] - dp[h] <= n / 2)
                ans[x] = true;
            else
                ans[x] = false;
            break;
        }
    }
    multiset<int> u;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            u.insert(dpp);
            continue;
        }
        u.insert(dp[h]);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        u.erase(u.find(dp[h]));
        int ydpp = 0;
        if (!u.empty())
            ydpp = *(--u.end());
        if (n - s[h] <= n / 2)
            ydpp = n - s[h];
        dfs1(h, x, ydpp);
        u.insert(dp[h]);
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
    dfs0(1, 1);
    dfs1(1, 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i])
            printf("1 ");
        else
            printf("0 ");
    }
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