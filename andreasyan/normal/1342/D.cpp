#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, k;
int a[N];
int c[N];

vector<int> ans[N];

int f(int u)
{
    int l = 1, r = k;
    int bans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (c[m] > ans[u].size())
        {
            bans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return bans;
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &c[i]);
    set<pair<int, int> > s;
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        set<pair<int, int> >::iterator it = s.lower_bound(m_p(a[i], -1));
        int u;
        if (it == s.end())
        {
            u = s.size() + 1;
            s.insert(m_p(k, u));
        }
        else
            u = it->second;
        s.erase(m_p(f(u), u));
        ans[u].push_back(a[i]);
        s.insert(m_p(f(u), u));
    }
    printf("%d\n", s.size());
    for (int i = 1; i <= s.size(); ++i)
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}