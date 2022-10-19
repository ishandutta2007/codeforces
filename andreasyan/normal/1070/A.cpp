#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5103, D = 502, INF = 1000000009;

int d, s;
int dp[N][D];
int u[N][D];

struct ban
{
    int x, d;
    ban(){}
    ban(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

bool c[D];
vector<int> a[N];

int main()
{
    scanf("%d%d", &d, &s);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < D; ++j)
        {
            dp[i][j] = INF;
        }
    }
    dp[s][0] = 0;
    for (int i = s; i >= 0; --i)
    {
        for (int j = 0; j < d; ++j)
        {
            for (int k = 1; k < 10; ++k)
            {
                if (dp[i + k][(j * 10 + k) % d] + 1 < dp[i][j])
                {
                    dp[i][j] = dp[i + k][(j * 10 + k) % d] + 1;
                    u[i][j] = k;
                }
            }
        }
        memset(c, false, sizeof c);
        for (int j = 0; j < d; ++j)
        {
            a[j].clear();
        }
        for (int j = 0; j < d; ++j)
        {
            a[(j * 10) % d].push_back(j);
        }
        priority_queue<ban> q;
        for (int j = 0; j < d; ++j)
        {
            ban t = ban(j, dp[i][j]);
            for (int i = 0; i < a[t.x].size(); ++i)
            {
                ban h = ban(a[t.x][i], t.d + 1);
                if (!c[h.x])
                    q.push(h);
            }
        }
        while (1)
        {
            ban t;
            bool z = false;
            while (1)
            {
                if (q.empty())
                    break;
                t = q.top();
                q.pop();
                if (!c[t.x])
                {
                    z = true;
                    break;
                }
            }
            if (!z)
                break;
            c[t.x] = true;
            if (t.d <= dp[i][t.x])
            {
                u[i][t.x] = 0;
                dp[i][t.x] = t.d;
            }
            for (int i = 0; i < a[t.x].size(); ++i)
            {
                ban h = ban(a[t.x][i], t.d + 1);
                if (!c[h.x])
                    q.push(h);
            }
        }
    }
    int i = 0, j = 0;
    if (dp[i][j] == INF)
    {
        printf("-1\n");
        return 0;
    }
    while (1)
    {
        if (i == s && j == 0)
            break;
        printf("%d", u[i][j]);
        int ii = i + u[i][j];
        int jj = (j * 10 + u[i][j]) % d;
        i = ii;
        j = jj;
    }
    printf("\n");
    return 0;
}