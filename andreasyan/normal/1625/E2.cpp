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
const int N = 300005, S = 4500;

struct ban
{
    int i;
    int l, r, t;
};
bool operator<(const ban& a, const ban& b)
{
    if (m_p(a.l / S, a.r / S) < m_p(b.l / S, b.r / S))
        return true;
    if (m_p(a.l / S, a.r / S) > m_p(b.l / S, b.r / S))
        return false;
    return a.t < b.t;
}

int n, qq;
char a[N];
int m;
ban b[N];
vector<pair<int, int> > v;

int p[N];
int c[N];
int cc[N];

ll yans;
int q[N];

void ave(int x)
{
    if (x == 0)
        return;
    yans += q[x];
    ++q[x];
}

void han(int x)
{
    if (x == 0)
        return;
    --q[x];
    yans -= q[x];
}

ll ans[N];

void solv()
{
    cin >> n >> qq;
    cin >> (a + 1);

    set<int> se;
    for (int i = 0; i <= n; ++i)
        se.insert(i);
    for (int i = 0; i < qq; ++i)
    {
        int ty, l, r;
        cin >> ty >> l >> r;
        if (ty == 1)
        {
            v.push_back(m_p(l, r));
            se.erase(l);
            se.erase(r);
        }
        else
        {
            b[m].l = *(--se.find(l));
            b[m].r = r;
            b[m].t = sz(v) - 1;
            b[m].i = m;
            m++;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] == '(')
            ++p[i];
        else
            --p[i];
    }

    stack<int> s;
    int z = 0;
    map<int, pair<int, int> > mp;
    for (int i = 0; i <= n; ++i)
    {
        while (!s.empty() && p[s.top()] >= p[i])
            s.pop();
        if (s.empty())
        {
            if (mp.find(-1) == mp.end() || mp[-1].fi != p[i])
                mp[-1] = m_p(p[i], ++z);
            c[i] = mp[-1].se;
        }
        else
        {
            if (mp.find(s.top()) == mp.end() || mp[s.top()].fi != p[i])
                mp[s.top()] = m_p(p[i], ++z);
            c[i] = mp[s.top()].se;
        }
        s.push(i);
    }
    for (int i = 0; i <= n; ++i)
        cc[i] = c[i];

    sort(b, b + m);
    int l = 0, r = -1, t = -1;
    for (int i = 0; i < m; ++i)
    {
        while (r < b[i].r)
        {
            ++r;
            ave(c[r]);
        }
        while (l > b[i].l)
        {
            --l;
            ave(c[l]);
        }
        while (r > b[i].r)
        {
            han(c[r]);
            --r;
        }
        while (l < b[i].l)
        {
            han(c[l]);
            ++l;
        }
        while (t < b[i].t)
        {
            ++t;
            if (l <= v[t].fi && v[t].fi <= r)
                han(c[v[t].fi]);
            if (l <= v[t].se && v[t].se <= r)
                han(c[v[t].se]);
            c[v[t].fi] = c[v[t].se] = 0;
        }
        while (t > b[i].t)
        {
            c[v[t].fi] = cc[v[t].fi];
            c[v[t].se] = cc[v[t].se];
            if (l <= v[t].fi && v[t].fi <= r)
                ave(c[v[t].fi]);
            if (l <= v[t].se && v[t].se <= r)
                ave(c[v[t].se]);
            --t;
        }

        ans[b[i].i] = yans;
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
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