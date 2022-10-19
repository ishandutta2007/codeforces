#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
vector<int> a[N];

int dp[N];

void dfs(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
    set<int> s;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        s.insert(dp[h]);
    }
    if (s.size() > 1)
    {
        dp[x] = -1;
    }
    else
    {
        if (s.empty())
            dp[x] = 1;
        else
        {
            if (*s.begin() == -1)
                dp[x] = *s.begin();
            else
                dp[x] = *s.begin() + 1;
        }
    }
}

int ans = -1;

void dfs1(int x, int p, int dpp)
{
    map<int, int> mp;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            if (dpp != -2)
                mp[dpp]++;
            continue;
        }
        mp[dp[h]]++;
    }
    if (mp.begin()->first != -1)
    {
        if (mp.size() <= 2)
        {
            if (mp.size() == 1)
            {
                ans = mp.begin()->first;
            }
            else
            {
                ans = mp.begin()->first + (++mp.begin())->first;
            }
            while (ans % 2 == 0)
                ans /= 2;
        }
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        mp[dp[h]]--;
        if (mp[-1] != 0)
        {
            mp[dp[h]]++;
            continue;
        }
        if (mp[dp[h]] == 0)
        {
            mp.erase(dp[h]);
        }
        if (mp[-1] == 0)
        {
            mp.erase(-1);
        }
        if (mp.empty())
            dfs1(h, x, 1);
        else if (mp.size() == 1)
            dfs1(h, x, mp.begin()->first + 1);
        mp[dp[h]]++;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    dfs1(1, 1, -2);
    printf("%d\n", ans);
    return 0;
}