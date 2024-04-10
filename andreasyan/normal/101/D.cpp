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
const int N = 100005;

int n;
vector<pair<int, int> > a[N];

ll q[N], d[N], ans[N];

bool so(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    return (a.fi * b.se) < (a.se * b.fi);
}

void dfs(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].fi;
        int dd = a[x][i].se;
        if (h == p)
            continue;
        dfs(h, x);
        d[h] += 2 * dd;
        ans[h] += q[h] * dd;
        d[x] += d[h];
        q[x] += q[h];
    }
    vector<pair<ll, ll> > v;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].fi;
        if (h == p)
            continue;
        ans[x] += ans[h];
        v.push_back(m_p(d[h], q[h]));
    }
    sort(all(v), so);
    int s = 0;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        ans[x] += s * v[i].fi;
        s += v[i].se;
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    dfs(1, 1);
    //printf("%lld\n", ans[1]);
    printf("%.9f\n", (double)ans[1] / (n - 1));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}