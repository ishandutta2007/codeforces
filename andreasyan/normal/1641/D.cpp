#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 110005;

struct ban
{
    int w;
    int u[5];
};
bool operator<(const ban& a, const ban& b)
{
    return a.w < b.w;
}

int n, m;
ban a[N];
int t[N][(1 << 5)];

int ans = INT_MAX;

int l[N], r[N];

bool zz[(1 << 5)];
vector<int> v[N];
int q[N * (1 << 5)];
void solvv()
{
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    memset(q, 0, sizeof q);

    for (int i = 1; i <= n; ++i)
    {
        int mid = (l[i] + r[i]) / 2;
        v[mid].push_back(i);
    }

    for (int i = n; i >= 1; --i)
    {
        for (int x = 0; x < (1 << m); ++x)
            ++q[t[i][x]];
        for (int j = 0; j < sz(v[i]); ++j)
        {
            int qq = 0;
            for (int x = 0; x < (1 << m); ++x)
            {
                if (zz[x])
                    qq += q[t[v[i][j]][x]];
                else
                    qq -= q[t[v[i][j]][x]];
            }

            int mid = (l[v[i][j]] + r[v[i][j]]) / 2;
            if (qq)
            {
                ans = min(ans, a[i].w + a[v[i][j]].w);
                l[v[i][j]] = mid + 1;
            }
            else
                r[v[i][j]] = mid - 1;
        }
    }
}

ll R[N * 5];
void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> a[i].u[j];
        cin >> a[i].w;
    }

    for (int i = 1; i <= n; ++i)
        sort(a[i].u, a[i].u + m);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            v.push_back(a[i].u[j]);
        }
    }
    sort(all(v));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i].u[j] = lower_bound(all(v), a[i].u[j]) - v.begin() + 1;
        }
    }

    for (int i = 1; i <= sz(v); ++i)
        R[i] = rnd();

    vector<ll> vv;
    for (int i = 1; i <= n; ++i)
    {
        for (int x = 0; x < (1 << m); ++x)
        {
            ll h = 0;
            for (int j = 0; j < m; ++j)
            {
                if ((x & (1 << j)))
                    h ^= R[a[i].u[j]];
            }
            vv.push_back(h);
        }
    }
    sort(all(vv));

    for (int i = 1; i <= n; ++i)
    {
        for (int x = 0; x < (1 << m); ++x)
        {
            ll h = 0;
            for (int j = 0; j < m; ++j)
            {
                if ((x & (1 << j)))
                    h ^= R[a[i].u[j]];
            }
            t[i][x] = lower_bound(all(vv), h) - vv.begin() + 1;
        }
    }


    for (int i = 1; i <= n; ++i)
    {
        l[i] = i + 1;
        r[i] = n;
    }

    for (int x = 0; x < (1 << m); ++x)
    {
        for (int i = 0; i < m; ++i)
        {
            if ((x & (1 << i)))
                zz[x] ^= true;
        }
    }

    while (1)
    {
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            if (l[i] <= r[i])
            {
                z = true;
                break;
            }
        }
        if (!z)
            break;

        solvv();
    }

    if (ans == INT_MAX)
        cout << "-1\n";
    else
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