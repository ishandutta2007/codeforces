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
const int N = 4000006, m = 23;

int n;
int a[N];

int q[(1 << m)];

bool c[(1 << m)];
vector<int> v;
void dfs(int x)
{
    if (q[x] >= 2)
        return;
    if (c[x])
        return;
    ++q[x];
    c[x] = true;
    v.push_back(x);
    for (int i = 0; i < m; ++i)
    {
        if ((x & (1 << i)))
            dfs((x ^ (1 << i)));
    }
}

bool stg(int x)
{
    memset(q, 0, sizeof q);
    for (int i = n; i >= 1; --i)
    {
        int u = (a[i] & x);
        if (q[(u ^ x)] >= 2)
            return true;
        dfs(u);
        for (int i = 0; i < sz(v); ++i)
            c[v[i]] = false;
        v.clear();
    }
    return false;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        ans += (1 << i);
        if (stg(ans))
            continue;
        ans -= (1 << i);
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