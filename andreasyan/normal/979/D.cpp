#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005, INF = 1000000009;
struct ban
{
    int u[2];
};

vector<int> v[N];

bool c[N];

const int m = 19;
int z[N];
vector<ban> t[N];
vector<int> y[N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    for (int i = 1; i < N; ++i)
    {
        t[i].push_back({0, 0});
        y[i].push_back(INF);
        for (int j = i; j < N; j += i)
        {
            v[j].push_back(i);
        }
    }
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x;
            scanf("%d", &x);
            if (c[x])
                continue;
            c[x] = true;
            for (int i = 0; i < v[x].size(); ++i)
            {
                int u = v[x][i];
                int pos = 0;
                y[u][pos] = min(y[u][pos], x);
                for (int j = m - 1; j >= 0; --j)
                {
                    int b;
                    if ((x & (1 << j)))
                        b = 1;
                    else
                        b = 0;
                    if (!t[u][pos].u[b])
                    {
                        t[u][pos].u[b] = ++z[u];
                        t[u].push_back({0, 0});
                        y[u].push_back(INF);
                    }
                    pos = t[u][pos].u[b];
                    y[u][pos] = min(y[u][pos], x);
                }
            }
        }
        else
        {
            int x, k, s;
            scanf("%d%d%d", &x, &k, &s);
            if (x % k != 0)
            {
                printf("-1\n");
                continue;
            }
            if (!(y[k][0] <= s - x))
            {
                printf("-1\n");
                continue;
            }
            int pos = 0;
            for (int i = m - 1; i >= 0; --i)
            {
                int b;
                if ((x & (1 << i)))
                    b = 1;
                else
                    b = 0;
                if (t[k][pos].u[(b ^ 1)] != 0 && y[k][t[k][pos].u[(b ^ 1)]] <= s - x)
                    pos = t[k][pos].u[(b ^ 1)];
                else
                    pos = t[k][pos].u[b];
            }
            printf("%d\n", y[k][pos]);
        }
    }
    return 0;
}