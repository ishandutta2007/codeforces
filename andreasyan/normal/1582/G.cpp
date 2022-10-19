#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int N = 1000006;
 
int u[N];
void pre()
{
    u[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}
 
int n;
int a[N];
char b[N];
 
vector<pair<int, int> > v[N];
 
int t[N * 44];
 
void ubd(int x, int y)
{
    while (x < N * 44)
    {
        t[x] = min(t[x], y);
        x += (x & (-x));
    }
}
 
void clr(int x)
{
    while (x < N * 44)
    {
        t[x] = N;
        x += (x & (-x));
    }
}
 
int qry(int x)
{
    int ans = N;
    while (x)
    {
        ans = min(ans, t[x]);
        x -= (x & (-x));
    }
    return ans;
}
 
vector<pair<int, int> > uv[N];
 
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> (b + 1);
 
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        int p = u[x];
        int q = 0;
        while (x != 1)
        {
            if (u[x] == p)
            {
                ++q;
            }
            else
            {
                if (b[i] == '*')
                    v[p].push_back(m_p(i, q));
                else
                    v[p].push_back(m_p(i, -q));
                p = u[x];
                q = 1;
            }
            x /= u[x];
        }
        if (p > 1)
        {
            if (b[i] == '*')
                v[p].push_back(m_p(i, q));
            else
                v[p].push_back(m_p(i, -q));
        }
    }
 
    for (int i = 0; i < N * 44; ++i)
        t[i] = N;
 
    for (int p = 2; p < N; ++p)
    {
        if (v[p].empty())
            continue;
 
        vector<int> pp;
        pp.push_back(0);
        for (int i = 0; i < sz(v[p]); ++i)
            pp.push_back(pp.back() + v[p][i].se);
 
        int minu = 0;
        for (int i = 0; i < sz(pp); ++i)
            minu = min(minu, pp[i]);
        --minu;
        for (int i = 0; i < sz(pp); ++i)
            pp[i] -= minu;
 
        for (int i = sz(v[p]) - 1; i >= 0; --i)
        {
            int l0 = 1;
            if (i)
                l0 = v[p][i - 1].fi + 1;
 
            ubd(pp[i + 1], i);
 
            int j = qry(pp[i] - 1);
 
            if (j < N)
                uv[v[p][j].fi].push_back(m_p(l0, v[p][i].fi));
        }
 
        for (int i = sz(v[p]) - 1; i >= 0; --i)
            clr(pp[i + 1]);
    }
 
    ll ans = 0;
 
    set<int> s;
 
    for (int r = 1; r <= n; ++r)
    {
        s.insert(r);
        for (int i = 0; i < sz(uv[r]); ++i)
        {
            int ul = uv[r][i].fi;
            int ur = uv[r][i].se;
 
            while (!s.empty())
            {
                auto it = s.lower_bound(ul);
                if (it != s.end() && *it <= ur)
                {
                    s.erase(it);
                }
                else
                    break;
            }
        }
 
        ans += sz(s);
    }
 
    cout << ans << "\n";
}
 
int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
 
    pre();
 
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}