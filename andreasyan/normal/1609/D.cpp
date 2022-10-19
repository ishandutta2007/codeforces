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
const int N = 1003;

int n, m;
int p[N];
int q[N], k[N];

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
    q[y] += q[x];
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        q[i] = 1;
        k[i] = 0;
    }

    for (int j = 1; j <= m; ++j)
    {
        int x, y;
        cin >> x >> y;
        if (fi(x) != fi(y))
        {
            kpc(x, y);
        }

        vector<int> v;
        int u = j;
        for (int x = 1; x <= n; ++x)
        {
            if (x == fi(x))
            {
                v.push_back(q[x]);
                u -= (q[x] - 1);
            }
        }

        sort(all(v));
        reverse(all(v));
        ++u;
        int ans = 0;
        for (int i = 0; i < min(sz(v), u); ++i)
            ans += v[i];

        cout << ans - 1 << "\n";
    }
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