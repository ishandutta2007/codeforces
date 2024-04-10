#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1003, M = 10004;
const int INF = 1000000009;
struct ban
{
    int x;
    long long d;
    ban(){}
    ban(int x, long long d)
    {
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int n, m, L, s, f;
pair<pair<int, int>, int> b[M];
vector<ban> a[N];
vector<int> aa[N];

void clr()
{
    for (int i = 0; i < n; ++i)
        a[i].clear();
}

long long d[N];
bool c[N];
int p[N];
int pp[N];

void djk()
{
    memset(c, false, sizeof c);
    for (int i = 0; i < n; ++i)
        d[i] = INF;
    priority_queue<ban> q;
    q.push(ban(s, 0));
    d[s] = 0;
    while (!q.empty())
    {
        ban t;
        do
        {
            if (q.empty())
                return;
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        for (int i = 0; i < a[t.x].size(); ++i)
        {
            ban h = a[t.x][i];
            h.d += t.d;
            if (!c[h.x] && h.d < d[h.x])
            {
                p[h.x] = t.x;
                pp[h.x] = aa[t.x][i];
                d[h.x] = h.d;
                q.push(h);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d%d", &n, &m, &L, &s, &f);
    for (int i = 0; i < m; ++i)
    {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        b[i] = m_p(m_p(x, y), d);
        aa[x].push_back(i);
        aa[y].push_back(i);
    }
    clr();
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].first.first, y = b[i].first.second, d = b[i].second;
        if (d)
        {
            a[x].push_back(ban(y, d));
            a[y].push_back(ban(x, d));
        }
        else
        {
            a[x].push_back(ban(y, INF));
            a[y].push_back(ban(x, INF));
        }
    }
    djk();
    if (d[f] < L)
    {
        printf("NO\n");
        return 0;
    }
    clr();
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].first.first, y = b[i].first.second, d = b[i].second;
        if (d)
        {
            a[x].push_back(ban(y, d));
            a[y].push_back(ban(x, d));
        }
        else
        {
            a[x].push_back(ban(y, 1));
            a[y].push_back(ban(x, 1));
        }
    }
    djk();
    if (d[f] > L)
    {
        printf("NO\n");
        return 0;
    }
    while (1)
    {
        clr();
        for (int i = 0; i < m; ++i)
        {
            int x = b[i].first.first, y = b[i].first.second, d = b[i].second;
            if (d)
            {
                a[x].push_back(ban(y, d));
                a[y].push_back(ban(x, d));
            }
            else
            {
                a[x].push_back(ban(y, 1));
                a[y].push_back(ban(x, 1));
            }
        }
        djk();
        if (d[f] == L)
        {
            printf("YES\n");
            for (int i = 0; i < m; ++i)
            {
                int x = b[i].first.first, y = b[i].first.second, d = b[i].second;
                if (d)
                    printf("%d %d %d\n", x, y, d);
                else
                    printf("%d %d 1\n", x, y);
            }
            return 0;
        }
        int x = f;
        while (x != s)
        {
            if (b[pp[x]].second == 0)
            {
                b[pp[x]].second = L - d[f] + 1;
                break;
            }
            x = p[x];
        }
    }
    return 0;
}