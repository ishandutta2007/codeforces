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
const int N = 200005, INF = 1000000009;

int n;
int a[N], b[N], c[N], d[N];

bool hh[N];

pair<int, int> t[N * 4];
void ubd(int tl, int tr, int x, pair<int, int> y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(INF, INF);
    if (tl == l && tr == r)
    {
        return t[pos];
    }
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

bool color[N];
int dist[N];
int p[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        if (a[i] == 0 && b[i] == 0)
            hh[i] = true;
    }

    vector<pair<int, int> > v;
    v.push_back(m_p(0, 0));
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(m_p(a[i], -i));
        v.push_back(m_p(c[i], i));
    }
    sort(all(v));

    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i].se < 0)
            a[-v[i].se] = i + 1;
        else
            c[v[i].se] = i + 1;
    }

    for (int i = 0; i < N * 4; ++i)
        t[i] = m_p(INF, INF);

    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (hh[i])
        {
            dist[i] = 1;
            color[i] = true;
            p[i] = 0;
            q.push(i);
        }
        else
        {
            ubd(1, sz(v), a[i], m_p(b[i], i), 1);
        }
    }

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        if (i == n)
        {
            cout << dist[i] << "\n";
            vector<int> ans;
            int x = i;
            while (x)
            {
                ans.push_back(x);
                x = p[x];
            }
            reverse(all(ans));
            assert(sz(ans) == dist[i]);
            for (int i = 0; i < sz(ans); ++i)
                cout << ans[i] << ' ';
            cout << "\n";
            return;
        }

        while (1)
        {
            pair<int, int> u = qry(1, sz(v), 1, c[i], 1);
            if (u.fi <= d[i])
            {
                dist[u.se] = dist[i] + 1;
                color[u.se] = true;
                p[u.se] = i;
                q.push(u.se);
                ubd(1, sz(v), a[u.se], m_p(INF, INF), 1);
            }
            else
                break;
        }
    }

    cout << "-1\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}