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
const int N = 303;

struct ban
{
    int x, y, z;
    int o;
};
bool operator<(const ban& a, const ban& b)
{
    return a.z < b.z;
}

int n, m;
ban b[N];
ban a[N];

int p0[N];
int fi(int x)
{
    if (x == p0[x])
        return x;
    return p0[x] = fi(p0[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p0[x] = y;
}

vector<int> t;
vector<vector<int> > v;
vector<vector<ll> > p;
ll qry(int x)
{
    int i = upper_bound(all(t), x) - t.begin() - 1;

    int j = lower_bound(all(v[i]), x) - v[i].begin();

    ll ans = 0;
    ans += j * 1LL * x;
    if (j - 1 >= 0)
        ans -= p[i][j - 1];
    ans += p[i].back();
    if (j - 1 >= 0)
        ans -= p[i][j - 1];
    ans -= (sz(v[i]) - j) * 1LL * x;

    return ans;
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i].x >> b[i].y >> b[i].z;
        b[i].z *= 2;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = i + 1; j <= m; ++j)
        {
            t.push_back((b[i].z + b[j].z) / 2 + 1);
        }
    }
    t.push_back(-1);
    sort(all(t));

    for (int i = 0; i < sz(t); ++i)
    {
        v.push_back({});
        for (int j = 1; j <= m; ++j)
        {
            a[j] = b[j];
            a[j].z = abs(b[j].z - t[i]);
            a[j].o = b[j].z;
        }
        sort(a + 1, a + m + 1);

        for (int x = 1; x <= n; ++x)
            p0[x] = x;
        for (int j = 1; j <= m; ++j)
        {
            if (fi(a[j].x) != fi(a[j].y))
            {
                kpc(a[j].x, a[j].y);
                v[i].push_back(a[j].o);
            }
        }
        sort(all(v[i]));

        p.push_back({});
        p[i].assign(sz(v[i]), 0);
        p[i][0] = v[i][0];
        for (int j = 1; j < sz(v[i]); ++j)
            p[i][j] = p[i][j - 1] + v[i][j];
    }

    int q0, q1, aa, bb, cc;
    cin >> q0 >> q1 >> aa >> bb >> cc;

    ll ans = 0;
    int x;
    for (int i = 0; i < q0; ++i)
    {
        cin >> x;
        ans ^= (qry(x * 2) / 2);
    }
    for (int i = 0; i < q1 - q0; ++i)
    {
        x = (x * 1LL * aa + bb) % cc;
        ans ^= (qry(x * 2) / 2);
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}