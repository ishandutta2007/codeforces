#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const long long INF = 10004000000009;
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

int n, m;
int s, f;
vector<ban> a[N];
pair<int, int> b[N];

long long d[N][N];
bool c[N];
void djk(int x)
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;

    priority_queue<ban> q;

    q.push(ban(x, 0));
    while (1)
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
        d[x][t.x] = t.d;
        for (int i = 0; i < a[t.x].size(); ++i)
        {
            ban h = a[t.x][i];
            h.d += t.d;
            if (!c[h.x])
                q.push(h);
        }
    }
}

vector<ban> g[N];

long long djk1()
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;

    priority_queue<ban> q;

    q.push(ban(s, 0));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
                return -1;
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        if (t.x == f)
            return t.d;
        for (int i = 0; i < g[t.x].size(); ++i)
        {
            ban h = g[t.x][i];
            h.d += t.d;
            if (!c[h.x])
                q.push(h);
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> s >> f;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(ban(y, z));
        a[y].push_back(ban(x, z));
    }

    for (int i = 1; i <= n; ++i)
        cin >> b[i].first >> b[i].second;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            d[i][j] = INF;
    }

    for (int i = 1; i <= n; ++i)
        djk(i);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (d[i][j] <= b[i].first)
            {
                g[i].push_back(ban(j, b[i].second));
            }
        }
    }

    cout << djk1() << endl;
    return 0;
}