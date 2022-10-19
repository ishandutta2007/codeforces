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
const int N = 400005, M = 1000006;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int u[M];
void pre()
{
    u[1] = 1;
    for (int i = 2; i < M; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < M; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n;
int a[N];

vector<int> v[N];

int d[M];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n * 2; ++i)
        v[i].clear();

    int g = 0;
    for (int i = 0; i < n; ++i)
        g = gcd(g, a[i]);
    for (int i = 0; i < n; ++i)
        a[i] /= g;

    for (int i = n; i < n * 2; ++i)
        a[i] = a[i - n];

    for (int i = 0; i < n * 2; ++i)
    {
        int x = a[i];
        while (x > 1)
        {
            if (v[i].empty() || v[i].back() != u[x])
                v[i].push_back(u[x]);
            x /= u[x];
        }
    }

    for (int j = 0; j < v[n * 2 - 1].size(); ++j)
        d[v[n * 2 - 1][j]] = n * 2;

    for (int i = n * 2 - 2; i >= n; --i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (!binary_search(all(v[i + 1]), v[i][j]))
                d[v[i][j]] = i + 1;
        }
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int maxu = i;
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (!binary_search(all(v[i + 1]), v[i][j]))
                d[v[i][j]] = i + 1;
            maxu = max(maxu, d[v[i][j]]);
        }
        ans = max(ans, maxu - i);
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}