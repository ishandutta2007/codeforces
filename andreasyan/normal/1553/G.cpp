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
vector<int> v[N];
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

    for (int i = 1; i < N; ++i)
    {
        int x = i;
        while (x > 1)
        {
            if (v[i].empty() || u[x] != v[i].back())
                v[i].push_back(u[x]);
            x /= u[x];
        }
    }
}

int n, qq;
int a[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i < N; ++i)
        p[i] = i;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(v[a[i]]); ++j)
        {
            kpc(v[a[i]][j], a[i]);
        }
    }

    set<pair<int, int> > s;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> vv;
        for (int j = 0; j < sz(v[a[i]]); ++j)
            vv.push_back(v[a[i]][j]);
        for (int j = 0; j < sz(v[a[i] + 1]); ++j)
            vv.push_back(v[a[i] + 1][j]);
        for (int j = 0; j < sz(vv); ++j)
        {
            for (int k = j + 1; k < sz(vv); ++k)
            {
                if (fi(vv[j]) != fi(vv[k]))
                    s.insert(m_p(min(fi(vv[j]), fi(vv[k])), max(fi(vv[j]), fi(vv[k]))));
            }
        }
    }

    while (qq--)
    {
        int x, y;
        cin >> x >> y;
        x = a[x];
        y = a[y];

        if (fi(x) == fi(y))
        {
            cout << "0\n";
        }
        else if (s.find(m_p(min(fi(x), fi(y)), max(fi(x), fi(y)))) != s.end())
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }
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
    {
        solv();
    }
    return 0;
}