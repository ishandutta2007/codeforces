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

struct ban
{
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    return m_p(a.x, a.y) < m_p(b.x, b.y);
}
double dist(const ban& a, const ban& b)
{
    return sqrt((a.x - b.x) * 1LL * (a.x - b.x) + (a.y - b.y) * 1LL * (a.y - b.y));
}

ll F(const ban& t1, const ban& t2, const ban& t)
{
    return (t.x - t1.x) * 1LL * (t2.y - t1.y) - (t.y - t1.y) * 1LL * (t2.x - t1.x);
}

int n, k;
ban a[N];
bool so(int i, int j)
{
    return a[i] < a[j];
}

bool c[N];

double solv()
{
    int u = -1;
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = i + 1; j <= 3; ++j)
        {
            int q = 0;
            for (int k = 1; k <= n; ++k)
            {
                if (F(a[i], a[j], a[k]))
                    ++q;
            }
            if (q == 1)
            {
                for (int k = 1; k <= n; ++k)
                {
                    if (F(a[i], a[j], a[k]))
                    {
                        u = k;
                        break;
                    }
                }
            }
        }
    }
    assert(u != -1);

    c[u] = true;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (i == u)
            continue;
        v.push_back(i);
    }
    sort(all(v), so);

    double ans = INF;
    if (k == u)
    {
        for (int i = 0; i < sz(v); ++i)
        {
            ans = min(ans, dist(a[k], a[v[i]]) + dist(a[v[0]], a[v.back()]) * 2 - max(dist(a[v[i]], a[v[0]]), dist(a[v[i]], a[v.back()])));
        }
    }
    else
    {
        ans = min(ans, dist(a[v[0]], a[v.back()]) + dist(a[v[0]], a[k]) + dist(a[v.back()], a[u]));
        ans = min(ans, dist(a[v[0]], a[v.back()]) + dist(a[v.back()], a[k]) + dist(a[v[0]], a[u]));
        bool z = false;
        for (int i = 0; i < sz(v) - 1; ++i)
        {
            if (v[i] == k)
            {
                ans = min(ans, dist(a[k], a[v[0]]) + dist(a[v[0]], a[u]) + min(dist(a[u], a[v[i + 1]]), dist(a[u], a[v.back()])) + dist(a[v[i + 1]], a[v.back()]));
                z = true;
            }
            if (z)
                ans = min(ans, dist(a[v[0]], a[v[i]]) + dist(a[k], a[v[0]]) + dist(a[v[i]], a[u]) + dist(a[u], a[v[i + 1]]) + dist(a[v[i + 1]], a[v.back()]));
        }
        reverse(all(v));
        z = false;
        for (int i = 0; i < sz(v) - 1; ++i)
        {
            if (v[i] == k)
            {
                ans = min(ans, dist(a[k], a[v[0]]) + dist(a[v[0]], a[u]) + min(dist(a[u], a[v[i + 1]]), dist(a[u], a[v.back()])) + dist(a[v[i + 1]], a[v.back()]));
                z = true;
            }
            if (z)
                ans = min(ans, dist(a[v[0]], a[v[i]]) + dist(a[k], a[v[0]]) + dist(a[v[i]], a[u]) + dist(a[u], a[v[i + 1]]) + dist(a[v[i + 1]], a[v.back()]));
        }
    }

    return ans;
}

double solv0()
{
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (i == k)
            continue;
        v.push_back(i);
    }

    double ans = INF;
    do
    {
        double yans = dist(a[k], a[v[0]]);
        for (int i = 0; i < sz(v) - 1; ++i)
            yans += dist(a[v[i]], a[v[i + 1]]);
        ans = min(ans, yans);
    } while (next_permutation(all(v)));

    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            cin >> a[i].x >> a[i].y;

        set<pair<int, int> > s;
        c[k] = true;
        s.insert(m_p(a[k].x, a[k].y));
        for (int i = 1; i <= n; ++i)
        {
            if (s.find(m_p(a[i].x, a[i].y)) != s.end())
                continue;
            c[i] = true;
            s.insert(m_p(a[i].x, a[i].y));
        }

        vector<ban> v;
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
            {
                c[i] = false;
                v.push_back(a[i]);
                if (i == k && z == false)
                {
                    z = true;
                    k = sz(v);
                }
            }
        }
        n = sz(v);
        for (int i = 1; i <= n; ++i)
            a[i] = v[i - 1];

        cout << solv() << "\n";
        //cout << solv0() << "\n";
    }
    return 0;
}