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
const int N = 200005, M = 998244353;
const int k = 25;

int n, m;
vector<int> g[N], rg[N];

struct ban
{
    int x;
    int d;
    int q;
    ban(){}
    ban(int x, int d, int q)
    {
        this->x = x;
        this->d = d;
        this->q = q;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.q >= k && b.q >= k)
    {
        if (a.q > b.q)
            return true;
        if (a.q < b.q)
            return false;
        return a.d > b.d;
    }
    if (a.q >= k)
        return true;
    if (b.q >= k)
        return false;
    return a.d > b.d;
}

bool c[N][k + 1][2];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    priority_queue<ban> q;
    q.push(ban(1, 0, 0));
    while (1)
    {
        ban t;
        do
        {
            t = q.top();
            q.pop();
        } while(c[t.x][min(t.q, k)][t.q % 2]);
        c[t.x][min(t.q, k)][t.q % 2] = true;
        if (t.x == n)
        {
            int ans = t.d;
            int u = (1 << (k - 1));
            for (int i = k; i <= t.q; ++i)
            {
                ans = (ans + u) % M;
                u = (u + u) % M;
            }
            printf("%d\n", ans);
            return;
        }
        if (t.q % 2 == 0)
        {
            for (int i = 0; i < g[t.x].size(); ++i)
            {
                ban h;
                h.x = g[t.x][i];
                h.d = t.d + 1;
                h.q = t.q;
                q.push(h);
            }
        }
        else
        {
            for (int i = 0; i < rg[t.x].size(); ++i)
            {
                ban h;
                h.x = rg[t.x][i];
                h.d = t.d + 1;
                h.q = t.q;
                q.push(h);
            }
        }
        if (t.q + 1 >= k)
            q.push(ban(t.x, t.d, t.q + 1));
        else
            q.push(ban(t.x, t.d + (1 << t.q), t.q + 1));
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