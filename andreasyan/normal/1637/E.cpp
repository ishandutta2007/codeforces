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
const int N = 300005;

int n, m;
int a[N];
pair<int, int> b[N];

vector<int> u;
vector<int> v[N];

struct ban
{
    int x, y;
    int s;

    ban(){}
    ban(int i, int j, int x, int y)
    {
        this->x = x;
        this->y = y;
        s = v[u[i]][x] + v[u[j]][y];
    }
};

bool operator<(const ban& a, const ban& b)
{
    return a.s < b.s;
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i].fi >> b[i].se;
    sort(b, b + m);

    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
        mp[a[i]]++;

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        v[it->se].push_back(it->fi);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!v[i].empty())
            u.push_back(i);
    }

    ll ans = 0;
    priority_queue<ban> q;
    set<pair<int, int> > c;
    for (int i = 0; i < sz(u); ++i)
    {
        for (int j = i; j < sz(u); ++j)
        {
            while (!q.empty())
                q.pop();
            c.clear();

            q.push(ban(i, j, sz(v[u[i]]) - 1, sz(v[u[j]]) - 1));
            c.insert(m_p(sz(v[u[i]]) - 1, sz(v[u[j]]) - 1));

            while (!q.empty())
            {
                ban t = q.top();
                q.pop();

                int xx = v[u[i]][t.x];
                int yy = v[u[j]][t.y];
                if (xx != yy)
                {
                    if (xx > yy)
                        swap(xx, yy);
                    if (!binary_search(b, b + m, m_p(xx, yy)))
                    {
                        ans = max(ans, (u[i] + u[j]) * 1LL * (xx + yy));
                        break;
                    }
                }

                if (t.x > 0)
                {
                    --t.x;
                    if (c.find(m_p(t.x, t.y)) == c.end())
                    {
                        q.push(ban(i, j, t.x, t.y));
                        c.insert(m_p(t.x, t.y));
                    }
                    ++t.x;
                }
                if (t.y > 0)
                {
                    --t.y;
                    if (c.find(m_p(t.x, t.y)) == c.end())
                    {
                        q.push(ban(i, j, t.x, t.y));
                        c.insert(m_p(t.x, t.y));
                    }
                    ++t.y;
                }
            }
        }
    }

    cout << ans << "\n";

    for (int i = 0; i < sz(u); ++i)
        v[u[i]].clear();
    u.clear();
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}