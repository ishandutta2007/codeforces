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
const int N = 6, M = 1000000007;

int n;

inline int q(int x)
{
    int l = 0, r = 30;
    int u;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (x * (1LL << m) <= n)
        {
            u = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    if (x * (1LL << u) + (1LL << u) - 1 <= n)
        return (1 << (u + 1)) - 1;
    return (1 << u) + (n - x * (1 << u));
}

inline bool isp(int x, int y)
{
    if (y < x)
        return false;

    int l = 0, r = 30;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (y / (1 << m) == x)
            return true;
        if (y / (1 << m) < x)
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}

inline int comq(int x, const set<int>& s)
{
    assert(s.find(x) == s.end());
    int ans = 0;

    vector<int> v;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        v.push_back(*it);
    }

    vector<int> vv;
    int maxu = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        if (isp(v[i], x))
            maxu = max(maxu, v[i]);
        else
            vv.push_back(v[i]);
    }
    v = vv;

    vv.clear();
    for (int i = 0; i < sz(v); ++i)
    {
        bool z = true;
        for (int j = 0; j < sz(v); ++j)
        {
            if (i == j)
                continue;
            if (isp(v[j], v[i]))
            {
                z = false;
                break;
            }
        }
        if (z)
            vv.push_back(v[i]);
    }
    v = vv;

    while (1)
    {
        if (x == maxu)
            break;

        ans += q(x);

        vv.clear();
        for (int i = 0; i < sz(v); ++i)
        {
            if (isp(x, v[i]))
                ans -= q(v[i]);
            else
                vv.push_back(v[i]);
        }
        vv.push_back(x);
        v = vv;

        x /= 2;
    }

    return ans;
}


int comq0(int x, set<int> s)
{
    assert(s.find(x) != s.end());
    s.erase(x);
    int ans = 0;
    while (1)
    {
        if (x == 0 || s.find(x) != s.end())
            break;

        vector<int> v;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (isp(x, *it))
                v.push_back(*it);
        }

        ans += q(x);
        for (int i = 0; i < sz(v); ++i)
        {
            bool z = true;
            for (int j = 0; j < sz(v); ++j)
            {
                if (i == j)
                    continue;
                if (isp(v[j], v[i]))
                {
                    z = false;
                    break;
                }
            }
            if (z)
                ans -= q(v[i]);
        }

        s.insert(x);
        x /= 2;
    }

    return ans;
}

int m;
pair<int, int> b[N];

int ans;
vector<int> v;
void rec()
{
    if (!v.empty())
    {
        for (int xx = 0; xx < (1 << sz(v)); ++xx)
        {
            for (int i = 0; i < sz(v); ++i)
            {
                if ((xx & (1 << i)))
                    swap(b[v[i]].fi, b[v[i]].se);
            }

            bool z = true;
            set<int> s;

            if (s.find(b[v[0]].fi) != s.end())
            {
                z = false;
            }
            s.insert(b[v[0]].fi);
            for (int i = 0; i < sz(v) - 1; ++i)
            {
                int x = b[v[i]].se;
                int y = b[v[i + 1]].fi;

                while (1)
                {
                    if (x < y)
                        swap(x, y);
                    if (s.find(x) != s.end())
                    {
                        z = false;
                    }
                    s.insert(x);

                    if (x == y)
                        break;
                    x /= 2;
                }
            }
            if (s.find(b[v.back()].se) != s.end())
            {
                z = false;
            }
            s.insert(b[v.back()].se);

            if (z)
            {
                int x = b[v[0]].fi;
                int y = b[v.back()].se;

                vector<int> vx;
                while (!isp(x, y))
                {
                    vx.push_back(x);
                    x /= 2;
                }
                x = b[v[0]].fi;

                vector<int> vy;
                while (!isp(y, x))
                {
                    vy.push_back(y);
                    y /= 2;
                }

                vector<int> t;
                for (int i = 0; i < sz(vx); ++i)
                    t.push_back(vx[i]);
                t.push_back(y);
                for (int i = sz(vy) - 1; i >= 0; --i)
                    t.push_back(vy[i]);
                y = b[v.back()].se;

                assert(t[0] == x && t.back() == y);

                bool z = true;
                for (int i = 1; i < sz(t) - 1; ++i)
                {
                    if (s.find(t[i]) != s.end())
                    {
                        z = false;
                        break;
                    }
                }

                if (!z)
                {
                    ans = (ans + comq0(x, s) * 1LL * comq0(y, s)) % M;
                }
                else
                {
                    vector<int> su;
                    set<int> ss = s;
                    for (int j = sz(t) - 1; j >= 1; --j)
                    {
                        ss.insert(t[j - 1]);
                        su.push_back(comq0(t[j], ss));
                    }
                    su.push_back(0);
                    reverse(all(su));

                    for (int j = sz(t) - 2; j >= 0; --j)
                        su[j] = (su[j + 1] + su[j]) % M;

                    ss = s;
                    for (int i = 0; i < sz(t) - 1; ++i)
                    {
                        ss.insert(t[i + 1]);
                        ans = (ans + comq0(t[i], ss) * 1LL * su[i + 1]) % M;
                    }
                }
            }

            for (int i = 0; i < sz(v); ++i)
            {
                if ((xx & (1 << i)))
                    swap(b[v[i]].fi, b[v[i]].se);
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        bool z = true;
        for (int j = 0; j < sz(v); ++j)
        {
            if (v[j] == i)
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            v.push_back(i);
            rec();
            v.pop_back();
        }
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i].fi >> b[i].se;

    /*set<int> s;
    s.insert(2);
    s.insert(5);
    s.insert(10);
    cout << comq(5, s) << "\n";
    cout << comq0(5, s) << "\n";
    return;*/

    ans = (n * 1LL * n) % M;

    rec();

    cout << ans << "\n";
}

vector<int> g[1003];

int ans0;

bool c[1003];
void dfs(int x)
{
    c[x] = true;
    ++ans0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h);
    }
    c[x] = false;
}

void solv0()
{
    for (int i = 2; i <= n; ++i)
    {
        g[i].push_back(i / 2);
        g[i / 2].push_back(i);
    }
    for (int i = 0; i < m; ++i)
    {
        g[b[i].fi].push_back(b[i].se);
        g[b[i].se].push_back(b[i].fi);
    }

    ans0 = 0;
    for (int x = 1; x <= n; ++x)
    {
        dfs(x);
    }

    cout << ans0 << "\n";
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
        //solv0();
    }
    return 0;
}