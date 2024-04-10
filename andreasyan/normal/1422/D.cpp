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
const int N = 100005;
const ll INF = 1000000009000000009;

int n, m;
int x[N], y[N];

int sx, sy, fx, fy;

struct ban
{
    int u;
    ll d;
    ban(){}
    ban(int u, ll d)
    {
        this->u = u;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

bool c[N];

priority_queue<ban> q;
void ave(ban t, int u)
{
    q.push(ban(u, t.d + min(abs(x[t.u] - x[u]), abs(y[t.u] - y[u]))));
}

void solv()
{
    scanf("%d%d", &m, &n);
    scanf("%d%d", &sx, &sy);
    scanf("%d%d", &fx, &fy);
    x[0] = sx;
    y[0] = sy;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    vector<pair<int, int> > xx, yy;
    for (int i = 0; i <= n; ++i)
    {
        xx.push_back(m_p(x[i], i));
        yy.push_back(m_p(y[i], i));
    }
    sort(all(xx));
    sort(all(yy));

    ll ans = INF;

    q.push(ban(0, 0));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
            {
                printf("%lld\n", ans);
                return;
            }
            t = q.top();
            q.pop();
        } while (c[t.u]);
        c[t.u] = true;

        ans = min(ans, t.d + abs(x[t.u] - fx) + abs(y[t.u] - fy));

        auto it = upper_bound(all(xx), m_p(x[t.u], t.u));
        if (it != xx.end())
            ave(t, it->se);
        --it;
        if (it != xx.begin())
        {
            --it;
            ave(t, it->se);
        }

        it = upper_bound(all(yy), m_p(y[t.u], t.u));
        if (it != yy.end())
            ave(t, it->se);
        --it;
        if (it != yy.begin())
        {
            --it;
            ave(t, it->se);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}