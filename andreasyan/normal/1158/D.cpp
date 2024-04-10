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
const int N = 2003;

struct ban
{
    int i;
    int x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return m_p(a.x, a.y) < m_p(b.x, b.y);
}

int n;
ban a[N];

char s[N];

ll F(const ban& t1, const ban& t2, const ban& t3)
{
    return (t1.x - t3.x) * 1LL * (t1.y - t2.y) - (t1.x - t2.x) * 1LL * (t1.y - t3.y);
}

bool c[N];
vector<ban> convex()
{
    vector<ban> v;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            v.push_back(a[i]);
    }

    sort(all(v));

    vector<ban> u, d;

    u.push_back(v[0]);
    d.push_back(v[0]);
    for (int i = 1; i < sz(v); ++i)
    {
        // down
        if (i == sz(v) - 1 || F(v[0], v.back(), v[i]) > 0)
        {
            while (sz(d) >= 2 && F(d[sz(d) - 2], d.back(), v[i]) > 0)
                d.pop_back();
            d.push_back(v[i]);
        }
        // up
        if (i == sz(v) - 1 || F(v[0], v.back(), v[i]) < 0)
        {
            while (sz(u) >= 2 && F(u[sz(u) - 2], u.back(), v[i]) < 0)
                u.pop_back();
            u.push_back(v[i]);
        }
    }

    vector<ban> ans;

    for (int i = 0; i < sz(u); ++i)
        ans.push_back(u[i]);
    for (int i = sz(d) - 2; i > 0; --i)
        ans.push_back(d[i]);

    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        cin >> a[i].x >> a[i].y;
    }
    cin >> s;

    vector<int> ans;

    vector<ban> v = convex();
    int u1, u2;
    if (s[0] == 'R')
    {
        u1 = v[0].i;
        u2 = v[1].i;
    }
    else
    {
        u1 = v[1].i;
        u2 = v[0].i;
    }
    cout << u1 << ' ' << u2 << ' ';
    c[u1] = c[u2] = true;
    ans.push_back(u1);
    ans.push_back(u2);
    for (int i = 0; i < n - 2; ++i)
    {
        c[u1] = c[u2] = false;
        vector<ban> v = convex();
        c[u1] = c[u2] = true;
        vector<ban> nv = convex();

        int u3;
        if (s[i] == 'R' && s[i + 1] == 'R')
        {
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i].i == u2)
                {
                    u3 = v[(i + 1) % sz(v)].i;
                    break;
                }
            }
        }
        else if (s[i] == 'R' && s[i + 1] == 'L')
        {
            int nu1;
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i].i == u1)
                {
                    nu1 = v[(i - 1 + sz(v)) % sz(v)].i;
                    break;
                }
            }
            int hu2;
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i].i == u2)
                {
                    hu2 = v[(i + 1) % sz(v)].i;
                    break;
                }
            }
            for (int i = 0; i < sz(nv); ++i)
            {
                if (nv[i].i == nu1)
                {
                    u3 = nu1;
                    int j = i;
                    while (1)
                    {
                        j = (j + 1) % sz(nv);
                        if (nv[j].i == hu2)
                            break;
                        if (F(a[u2], nv[j], a[u3]) < 0)
                            u3 = nv[j].i;
                    }
                    break;
                }
            }
        }
        else if (s[i] == 'L' && s[i + 1] == 'L')
        {
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i].i == u2)
                {
                    u3 = v[(i - 1 + sz(v)) % sz(v)].i;
                    break;
                }
            }
        }
        else if (s[i] == 'L' && s[i + 1] == 'R')
        {
            int nu1;
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i].i == u1)
                {
                    nu1 = v[(i + 1) % sz(v)].i;
                    break;
                }
            }
            int hu2;
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i].i == u2)
                {
                    hu2 = v[(i - 1 + sz(v)) % sz(v)].i;
                    break;
                }
            }
            for (int i = 0; i < sz(nv); ++i)
            {
                if (nv[i].i == nu1)
                {
                    u3 = nu1;
                    int j = i;
                    while (1)
                    {
                        j = (j - 1 + sz(nv)) % sz(nv);
                        if (nv[j].i == hu2)
                            break;
                        if (F(a[u2], nv[j], a[u3]) > 0)
                            u3 = nv[j].i;
                    }
                    break;
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (!c[i])
                {
                    u3 = i;
                    break;
                }
            }
        }
        cout << u3 << ' ';
        c[u3] = true;
        ans.push_back(u3);
        u1 = u2;
        u2 = u3;
    }
    cout << "\n";

    for (int i = 0; i < sz(ans) - 2; ++i)
    {
        if (s[i] == 'L')
        {
            assert(F(a[ans[i]], a[ans[i + 1]], a[ans[i + 2]]) < 0);
        }
        else
        {
            assert(F(a[ans[i]], a[ans[i + 1]], a[ans[i + 2]]) > 0);
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}