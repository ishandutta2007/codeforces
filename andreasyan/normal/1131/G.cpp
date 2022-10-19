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
const int N = 250005, M = 10000007;

int n, m;
vector<int> aa[N], cc[N];

int a[M];
ll c[M];

int ul[M], ur[M];
int p[M];

ll dp[M];
ll d[M];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int q;
        cin >> q;
        for (int j = 0; j < q; ++j)
        {
            int x;
            cin >> x;
            aa[i].push_back(x);
        }
        for (int j = 0; j < q; ++j)
        {
            int x;
            cin >> x;
            cc[i].push_back(x);
        }
    }

    int qq;
    cin >> qq;
    int q = 0;
    while (qq--)
    {
        int i;
        int mu;
        cin >> i >> mu;

        for (int j = q + 1; j <= q + sz(aa[i]); ++j)
        {
            a[j] = aa[i][j - q - 1];
            c[j] = cc[i][j - q - 1] * 1LL * mu;
        }
        q += sz(aa[i]);
    }
    n = m;

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        ul[i] = i;
        while (!s.empty() && a[i] > i - s.top())
        {
            ul[i] = ul[s.top()];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        ur[i] = i;
        while (!s.empty() && a[i] > s.top() - i)
        {
            p[s.top()] = i;
            ur[i] = ur[s.top()];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[ul[i] - 1] + c[i];
        d[i] = dp[i - 1] + c[i];
        if (p[i])
            d[i] = min(d[i], d[p[i]]);
        dp[i] = min(dp[i], d[i]);
    }

    cout << dp[n] << "\n";
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