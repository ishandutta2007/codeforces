#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int n, m, k;
vector<int> a[N];

bool c[N];
int q;
void dfs(int x)
{
    c[x] = true;
    ++q;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int q1 = 0;
    int q2 = 0;
    int g2 = 0;
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ::q = 0;
            dfs(i);
            ::q = min(::q, k);
            if (::q == 1)
                ++q1;
            else
            {
                ++q2;
                g2 += ::q;
            }
            q.push(-::q);
        }
    }
    for (int ans = 0; ; ++ans)
    {
        if (q2)
        {
            if (g2 - (q2 - 1) * 2 - q1 >= 0)
            {
                printf("%d\n", ans);
                return;
            }
        }
        else
        {
            if (q1 <= 2)
            {
                printf("%d\n", ans);
                return;
            }
        }
        int x = -q.top();
        q.pop();
        int y = -q.top();
        q.pop();
        if (x == 1)
            --q1;
        else
        {
            --q2;
            g2 -= x;
        }
        if (y == 1)
            --q1;
        else
        {
            --q2;
            g2 -= y;
        }
        x += y;
        x = min(x, k);
        if (x == 1)
            ++q1;
        else
        {
            ++q2;
            g2 += x;
        }
        q.push(-x);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}