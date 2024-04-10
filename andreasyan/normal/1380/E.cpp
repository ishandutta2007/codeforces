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

int n, m;

int yans;
set<int> s[N];
int ans[N];

void clc()
{
    yans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ans[i] = 0;
        for (auto it = s[i].begin(); it != s[i].end(); ++it)
        {
            if (it == (--s[i].end()))
            {
                if (*it != n)
                {
                    ++ans[i];
                }
            }
            else
            {
                auto it1 = it;
                ++it1;
                if ((*it) + 1 != (*it1))
                {
                    ++ans[i];
                }
            }
        }
        yans += ans[i];
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        s[x].insert(i);
    }

    clc();

    printf("%d\n", yans);

    for (int ii = 0; ii < m - 1; ++ii)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (sz(s[y]) > sz(s[x]))
        {
            swap(s[x], s[y]);
            swap(ans[x], ans[y]);
        }
        yans -= ans[y];
        yans -= ans[x];
        ans[x] += ans[y];
        for (auto it = s[y].begin(); it != s[y].end(); ++it)
        {
            int u = *it;

            auto it1 = s[x].upper_bound(u);
            if (it1 != s[x].end())
            {
                if (u + 1 == *it1)
                    --ans[x];
            }
            if (it1 != s[x].begin())
            {
                --it1;
                if (*it1 + 1 == u)
                    --ans[x];
            }
        }
        for (auto it = s[y].begin(); it != s[y].end(); ++it)
        {
            s[x].insert(*it);
        }
        s[y].clear();
        yans += ans[x];

        //clc();
        printf("%d\n", yans);
    }
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