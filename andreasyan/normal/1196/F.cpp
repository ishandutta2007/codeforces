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

int n, m, k;
pair<int, pair<int, int> > b[N];

struct ban
{
    int x;
    ll d;
    ban(){}
    ban(int x, ll d)
    {
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

vector<ban> g[N];

set<pair<int, int> > s;
vector<ll> ans;

bool c[N];
void djk(int x)
{
    vector<int> v;
    priority_queue<ban> q;
    q.push(ban(x, 0));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
            {
                for (int i = 0; i < v.size(); ++i)
                    c[v[i]] = false;
                return;
            }
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        v.push_back(t.x);
        if (t.d)
            ans.push_back(t.d);
        for (int i = 0; i < g[t.x].size(); ++i)
        {
            ban h = g[t.x][i];
            h.d += t.d;
            if (!c[h.x])
                q.push(h);
        }
    }
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &b[i].se.fi, &b[i].se.se, &b[i].fi);
    }
    sort(b, b + m);
    for (int i = 0; i < min(m, k); ++i)
    {
        g[b[i].se.fi].push_back(ban(b[i].se.se, b[i].fi));
        g[b[i].se.se].push_back(ban(b[i].se.fi, b[i].fi));
    }
    for (int x = 1; x <= n; ++x)
        djk(x);
    sort(all(ans));
    printf("%lld\n", ans[2 * k - 1]);
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