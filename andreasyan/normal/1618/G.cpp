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
const int N = 400005;

int n, m, qq;
pair<int, bool> a[N];

pair<int, int> b[N];

ll pr[N];

int p[N];
int l[N], r[N];
int q[N];

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

    if (r[y] - l[y] < r[x] - l[x])
        swap(x, y);

    l[y] = min(l[y], l[x]);
    r[y] = max(r[y], r[x]);
    q[y] += q[x];
    p[x] = y;
}

ll yans[N];
void solv()
{
    cin >> n >> m >> qq;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].fi;
        a[i].se = true;
    }
    for (int i = n + 1; i <= n + m; ++i)
    {
        cin >> a[i].fi;
        a[i].se = false;
    }
    n += m;
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= qq; ++i)
    {
        cin >> b[i].fi;
        b[i].se = i;
    }

    vector<pair<int, int> > v;
    for (int i = 1; i < n; ++i)
    {
        v.push_back(m_p(a[i + 1].fi - a[i].fi, i));
    }
    sort(all(v));

    sort(b + 1, b + qq + 1);

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i].fi * a[i].se;
    for (int i = 1; i <= n; ++i)
        pr[i] = pr[i - 1] + a[i].fi;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        l[i] = r[i] = i;
        q[i] = a[i].se;
    }

    int j = 0;
    for (int i = 1; i <= qq; ++i)
    {
        while (j < sz(v) && v[j].fi <= b[i].fi)
        {
            int x = v[j].se;
            int y = v[j].se + 1;
            ++j;

            x = fi(x);
            y = fi(y);
            ans -= (pr[r[x]] - pr[r[x] - q[x]]);
            ans -= (pr[r[y]] - pr[r[y] - q[y]]);

            kpc(x, y);
            x = fi(x);
            ans += (pr[r[x]] - pr[r[x] - q[x]]);
        }

        yans[b[i].se] = ans;
    }

    for (int i = 1; i <= qq; ++i)
        cout << yans[i] << "\n";
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